#include "neuron.hh"

int main()
{
    srand(time(NULL));
    Perceptron neuron(2);

    std::list<std::pair<std::vector<double>, double>> set;
    std::pair<std::vector<double>, double> pair;
    pair.first = std::vector<double>(2);
    pair.first[0] = 0;
    pair.first[1] = 0;
    pair.second = 0;
    set.push_front(pair);
    pair.first[0] = 0;
    pair.first[1] = 1;
    pair.second = 0;
    set.push_front(pair);
    pair.first[0] = 1;
    pair.first[1] = 0;
    pair.second = 0;
    set.push_front(pair);
    pair.first[0] = 1;
    pair.first[1] = 1;
    pair.second = 1;
    set.push_front(pair);

    while (!neuron.train(0.1, set)){}

    std::vector<double> test(2);
    test[0] = rand() % 2;
    test[1] = rand() % 2;
    std::cout << test[0] << " " << test[1] << std::endl;
    std::cout << "result: " << neuron.compute(test) << std::endl;
    test[0] = rand() % 2;
    test[1] = rand() % 2;
    std::cout << test[0] << " " << test[1] << std::endl;
    std::cout << "result: " << neuron.compute(test) << std::endl;
    test[0] = rand() % 2;
    test[1] = rand() % 2;
    std::cout << test[0] << " " << test[1] << std::endl;
    std::cout << "result: " << neuron.compute(test) << std::endl;

    return 0;
}
