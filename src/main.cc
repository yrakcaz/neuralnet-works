#include <neuron.hh>
#include <cmath>

int main()
{
    srand(time(NULL));
    StepNeuron neuron;

    double inputs[4][2] = {
        { 0, 0 },
        { 0, 1 },
        { 1, 0 },
        { 1, 1 }
    };
    double outputs[4] = { 0, 0, 0, 1 };

    double tolerance = 0;
    double mark;
    do {
        std::list<Lesson> course;
        for (int i = 0; i < 4; i++)
            course.push_front(Lesson(std::vector<double>(inputs[i], inputs[i] + sizeof(inputs[i]) / sizeof(double)), outputs[i]));
        mark = 0;
        while (!course.empty()) {
            double error = neuron.learn(course.front());
            mark += std::abs(error);
            course.pop_front();
        }
        mark /= 4;
    } while (mark > tolerance);

    for (int i = 0; i < 4; i++) {
        std::cout << "weights: ";
        for (int j = 0; j < 2; j++) {
            std::cout << inputs[i][j] << " ";
        }
        std::cout << std::endl;

        std::cout << "expected: " << outputs[i] << std::endl;

        std::cout << "result: " << neuron.compute(std::vector<double>(inputs[i], inputs[i] + sizeof(inputs[i]) / sizeof(double))) << std::endl;
    }

    return 0;
}
