#ifndef TRAINING_HH
# define TRAINING_HH

# include <cmath>
# include <list>
# include <vector>

class Lesson {
    public:
        Lesson();
        Lesson(std::vector<double> inputs, double output);

        std::vector<double> inputs_get() const;
        void inputs_set(std::vector<double> inputs);

        double output_get() const;
        void output_set(double output);

    private:
        std::vector<double> inputs_;
        double output_;
};

class Neuron;

class Teacher {
    public:
        Teacher(double tolerance=0);

        void prepare_course(std::string course);
        bool teach(Neuron* neuron);
        bool validate(Neuron* neuron);

    private:
        double tolerance_;
        std::list<Lesson> course_;
};

#endif /* TRAINING_HH */
