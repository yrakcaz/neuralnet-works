#include <brain.hh>
#include <neuron.hh>
#include <training.hh>

#define DO_NOTHING_WITH(X) ((void)(X))

int main(int argc, char** argv)
{
    DO_NOTHING_WITH(argv);
    DO_NOTHING_WITH(argc);
    srand(time(NULL));
    MLP brain;
    brain.add_layer(2);
    brain.add_layer(2);
    brain.add_layer(1);
    std::vector<double> input(2);
    input[0] = 0;
    input[1] = 1;
    std::cout << brain.propagate(input)[0] << std::endl;
    return 0;

#if 0
    if (argc == 2) {
        //FIXME move it somewhere else.
        //      Brain could be a singleton containing it.
        //      But it would have to be generic enough to handle the `1 neuron` case.
        srand(time(NULL));

        Teacher teacher;
        Neuron *neuron = new StepNeuron();

        teacher.prepare_course(argv[1]);
        teacher.force_teach(neuron, 50);

        return !teacher.validate(neuron);
    }

    std::cerr << argv[0] << ": invalid arguments: use "
              << argv[0] << " <data>" << std::endl;

    return 1;
#endif
}
