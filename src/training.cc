#include <fstream>
#include <json/json.h>
#include <neuron.hh>
#include <training.hh>

Lesson::Lesson()
{
}

Lesson::Lesson(std::vector<double> inputs, double output)
    : inputs_(inputs)
    , output_(output)
{
}

std::vector<double> Lesson::inputs_get() const
{
    return inputs_;
}

void Lesson::inputs_set(std::vector<double> inputs)
{
    inputs_ = inputs;
}

double Lesson::output_get() const
{
    return output_;
}

void Lesson::output_set(double output)
{
    output_ = output;
}

Teacher::Teacher(double tolerance)
    : tolerance_(tolerance)
{
}

//FIXME clean it
void Teacher::prepare_course(std::string course)
{
    Json::Value root;
    Json::Reader reader;

    std::ifstream stream(course, std::ifstream::in);

    if (!reader.parse(stream, root)) {
        std::cerr  << "Failed to parse the JSON course:\n"
                   << reader.getFormattedErrorMessages();
        assert(false); //FIXME throw error?
    }

    const Json::Value datas = root["data"];
    for (auto data : datas) {
        const Json::Value inputs = data["input"];
        std::vector<double> input_vect(inputs.size());
        for (unsigned i = 0; i < inputs.size(); i++) {
            input_vect[i] = inputs[i].asDouble();
        }
        double output = data["output"].asDouble();
        Lesson lesson(input_vect, output);
        course_.push_back(lesson);
    }
}

bool Teacher::teach(Neuron* neuron)
{
    double moy = 0;

    for (auto lesson : course_) {
        double error = neuron->learn(lesson);
        moy += std::abs(error);
    }
    moy /= course_.size();

    return moy <= tolerance_;
}

bool Teacher::force_teach(Neuron* neuron, int max_it)
{
    for (int i = 0; !max_it || i < max_it; i++) {
        if (teach(neuron))
            return true;
    }
    return false;
}

bool Teacher::validate(Neuron* neuron)
{
    bool ret = true;

    for (auto lesson : course_) {
        std::vector<double> inputs = lesson.inputs_get();
        double output = lesson.output_get();
        double result = neuron->compute(inputs);

        if (std::abs(result - output) > tolerance_) {
            ret = false;
            std::cerr << "Learning failed... Try harder :p" << std::endl;
            break;
        }

#ifdef DEBUG
        std::cout << "weights: ";
        for (auto input : inputs) {
            std::cout << input << " ";
        }
        std::cout << std::endl;
        std::cout << "expected: " << output << std::endl;
        std::cout << "result: " << result << std::endl << std::endl;
#endif
    }

    if (ret)
        std::cout << "The learning was a success, GG WP!" << std::endl;

    return ret;
}
