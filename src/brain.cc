#include <brain.hh>

Layer::Layer(size_t size, enum neuron_type type, size_t nb_inputs)
    : neurons_(size)
    , size_(size)
{
    for (size_t i = 0; i < size; i++) {
        Neuron* neuron;

        switch (type) {
            case STEP_NEURON:
                neuron = new StepNeuron(nb_inputs);
                break;
            default:
                assert(false && "Unknown neuron type");
        }

        neurons_[i] = neuron;
    }
}

size_t Layer::size_get() {
    return size_;
}

std::vector<Neuron*> Layer::neurons_get()
{
    return neurons_;
}

MLP::MLP()
{
}

void MLP::add_layer(size_t size, enum neuron_type type)
{
    if (!layers_.size()) {
        layers_.push_back(Layer(size, type));
    } else {
        size_t nb_inputs = layers_.back().size_get();
        layers_.push_back(Layer(size, type, nb_inputs));
    }
}

//FIXME Clean it!
//      Use std::vector everywhere maybe?
std::vector<double> MLP::propagate(std::vector<double> inputs)
{
    if (layers_.front().size_get() != inputs.size())
        assert(false && "Invalid input count.");

    int counter = 0;
    std::list<double> outputs;

    for (Layer layer : layers_) {
#ifdef DEBUG
        std::cout << "Layer " << counter << ": " << std::endl;
#endif
        std::vector<Neuron*> neurons = layer.neurons_get();
        if (!counter) {
            for (size_t i = 0; i < inputs.size(); i++) {
                std::vector<double> input(1, inputs[i]);
                outputs.push_back(neurons[i]->compute(input));
            }
        } else {
            std::list<double> next_outputs;
            for (Neuron* neuron : neurons) {
                if (neuron->size_get() != outputs.size())
                    assert(false && "Invalid input count.");
                std::vector<double> input(outputs.begin(), outputs.end());
                next_outputs.push_back(neuron->compute(input));
            }
            outputs = next_outputs;
        }

#if DEBUG
        std::cout << "Outputs: ";
        for (double output : outputs)
            std::cout << output << " ";
        std::cout << std::endl << std::endl;
#endif

        counter++;
    }

    return std::vector<double>(outputs.begin(), outputs.end());
}
