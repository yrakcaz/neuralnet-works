#include <neuron.hh>
#include <training.hh>

int main(int argc, char** argv)
{
    if (argc == 2) {
        srand(time(NULL)); //FIXME put this somewhere else? teacher?

        Teacher teacher;
        Neuron *neuron = new StepNeuron();

        teacher.prepare_course(argv[1]);
        teacher.teach(neuron);
        return !teacher.validate(neuron);
    }

    std::cerr << argv[0] << ": invalid arguments: use "
              << argv[0] << " <data>" << std::endl;

    return 1;
}
