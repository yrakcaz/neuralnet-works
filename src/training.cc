#include <training.hh>

Lesson::Lesson()
{
}

Lesson::Lesson(std::vector<double> inputs, double output)
    : inputs_(inputs)
    , output_(output)
{
}

std::vector<double> Lesson::inputs_get()
{
    return inputs_;
}

void Lesson::inputs_set(std::vector<double> inputs)
{
    inputs_ = inputs;
}

double Lesson::output_get()
{
    return output_;
}

void Lesson::output_set(double output)
{
    output_ = output;
}
