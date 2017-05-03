#ifndef NEURON_HH
# define NEURON_HH

//FIXME remove unused
#include <cassert>
#include <iostream>
#include <training.hh>
#include <list>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <time.h>

//FIXME pass a Method in parameter instead?

class Neuron {
    public:
        Neuron(size_t nb_inputs=2);
        virtual double compute(std::vector<double>);
        double learn(Lesson lesson, double alpha=0.1);

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
