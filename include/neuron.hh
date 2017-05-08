#ifndef NEURON_HH
# define NEURON_HH

# include <cassert>
# include <iostream>
# include <string>
# include <training.hh>
# include <vector>

//FIXME pass a Method in parameter instead?

class Neuron {
    public:
        Neuron(size_t nb_inputs=2);
        virtual double compute(std::vector<double>);
        double learn(Lesson lesson, double alpha=0.1);
        size_t size_get();

    protected:
        std::vector<double> weights_;
        double threshold_;
};

enum neuron_type {
    STEP_NEURON,
};

class StepNeuron : public Neuron {
    public:
        StepNeuron(int nb_inputs=2);
        double compute(std::vector<double> inputs) override;
};

#endif /* !NEURON_HH */
