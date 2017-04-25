#ifndef TRAINING_HH
# define TRAINING_HH

#include <vector>

class Lesson {
    public:
        Lesson();
        Lesson(std::vector<double> inputs, double output);

        std::vector<double> inputs_get();
        void inputs_set(std::vector<double> inputs);

        double output_get();
        void output_set(double output);

    private:
        std::vector<double> inputs_;
        double output_;
};

#endif /* TRAINING_HH */
