#ifndef NEURON_HH
# define NEURON_HH

#include <cassert>
#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <time.h>

class Neuron {
    public:
        Neuron(int nb_inputs);
        virtual double compute(std::vector<double> inputs) = 0;
        bool train(double alpha,
                   std::list<std::pair<std::vector<double>, double>> set);

    protected:
        std::vector<double> weights_;
        double threshold_;
};

//FIXME change name?
class Perceptron : public Neuron {
    public:
        Perceptron(int nb_inputs);
        double compute(std::vector<double> inputs) override;
};

#endif /* !NEURON_HH */
