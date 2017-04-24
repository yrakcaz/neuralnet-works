#ifndef TRAINING_HH
# define TRAINING_HH

# include "neuron.hh"

class Lesson {
    public:
        Lesson();
        Lesson(std::vector<double> inputs, double output);

    private:
        std::vector<double> inputs_;
        double output_;
};

#endif /* TRAINING_HH */
