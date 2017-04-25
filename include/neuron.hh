#ifndef NEURON_HH
# define NEURON_HH

#include <cassert>
#include <iostream>
#include <training.hh>
#include <list>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <time.h>

class Neuron {
    public:
        Neuron(int nb_inputs=2);
        virtual double compute(std::vector<double> inputs) = 0;
        double learn(Lesson lesson, double alpha=0.1);

    protected:
        std::vector<double> weights_;
        double threshold_;
};

class StepNeuron : public Neuron {
    public:
        StepNeuron(int nb_inputs=2);
        double compute(std::vector<double> inputs) override;
};

#endif /* !NEURON_HH */
