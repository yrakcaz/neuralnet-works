#include "neuron.hh"

Neuron::Neuron(int nb_inputs)
    : weights_(nb_inputs)
{
    //FIXME More precision in random? Use alpha?
    threshold_ = 0;

    for (auto i = 0; i < weights_.size(); i++) {
        weights_[i] = rand() % 10;
        weights_[i] /= 10;
    }
}

bool Neuron::train(double alpha,
                   std::list<std::pair<std::vector<double>, double>> set)
{
    bool ret = true;

    //FIXME make something more useable! (train a pair only?...)
    while (!set.empty()) {
        auto pair = set.front();

        double error = -1;
        try { //FIXME test it
            error = pair.second - compute(pair.first);
        } catch (std::string e) {
            std::cerr << e << std::endl;
            assert(false);
        }
        if (error)
            ret = false;
        for (auto i = 0; i < weights_.size(); i++) {
            std::cout << "input" << i << ": " << pair.first[i] << std::endl;
        }
        std::cout << "output: " << pair.second << std::endl;
        std::cout << "error: " << error << std::endl;

        std::cout << "threshold: " << threshold_;
        std::cout << ", weights:";
        for(auto i = 0; i < weights_.size(); i++) {
            weights_[i] += alpha * pair.first[i] * error;
            std::cout << " " << weights_[i];
        }
        threshold_ -= alpha * error;
        std::cout << std::endl;

        set.pop_front();
    }
    std::cout << std::endl;

    return ret;
}

#define STEP(X) (X > 0 ? 1 : 0)

Perceptron::Perceptron(int nb_inputs)
    : Neuron(nb_inputs)
{
}

double Perceptron::compute(std::vector<double> inputs)
{
    if (inputs.size() != weights_.size()) {
        throw std::string("Invalid input count.");
    }

    double sum = 0;
    for (auto i = 0; i < weights_.size(); i++) {
        sum += inputs[i] * weights_[i];
    }

    return STEP(sum - threshold_);
}
