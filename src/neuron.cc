#include <neuron.hh>

Neuron::Neuron(size_t nb_inputs)
    : weights_(nb_inputs)
{
    //FIXME More precision in random? Use alpha?
    threshold_ = 0;

    for (size_t i = 0; i < weights_.size(); i++) {
        weights_[i] = rand() % 10;
        weights_[i] /= 10;
    }
}

double Neuron::learn(Lesson lesson, double alpha)
{
    try { //FIXME test it
        double error = lesson.output_get() - compute(lesson.inputs_get());
        threshold_ -= alpha * error;
        for (size_t i = 0; i < weights_.size(); i++) {
            weights_[i] += alpha * error * lesson.inputs_get()[i];

#ifdef DEBUG
        std::cout << "new threshold: " << threshold_ << std::endl;
        std::cout << "error: " << error << std::endl;
        std::cout << "new weight-" << i << ": " << weights_[i];
        std::cout << std::endl << std::endl;
#endif
        }

        return error;
    } catch (std::string e) {
        assert(false && e.c_str());
    }
}

double Neuron::compute(std::vector<double>) {
    assert(false && "Not implemented virtual function.");
}

#define STEP(X) (X > 0 ? 1 : 0)

StepNeuron::StepNeuron(int nb_inputs)
    : Neuron(nb_inputs)
{
}

double StepNeuron::compute(std::vector<double> inputs)
{
    if (inputs.size() != weights_.size()) {
        throw std::string("Invalid input count.");
    }

    double sum = 0;
    for (size_t i = 0; i < weights_.size(); i++) {
        sum += inputs[i] * weights_[i];
    }

    return STEP(sum - threshold_);
}
