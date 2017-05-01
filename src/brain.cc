#include <brain.hh>

Layer::Layer(size_t size, enum neuron_type type, size_t nb_inputs)
    : neurons_(size)
{
    for (size_t i = 0; i < size; i++) {
        Neuron neuron;

        switch (type) {
            case STEP_NEURON:
                neuron = StepNeuron(nb_inputs);
                break;
            default:
                assert(false && "Unknown neuron type");
        }

        neurons_[i] = neuron;
    }
}

MLP::MLP()
{
}

void MLP::add_layer(Layer layer)
{
    layers_.push_back(layer);
}
