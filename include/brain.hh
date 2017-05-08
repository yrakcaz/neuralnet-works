#ifndef BRAIN_HH
# define BRAIN_HH

# include "neuron.hh"

class Layer {
    public:
        Layer(size_t size, enum neuron_type type, size_t nb_inputs=1);
        size_t size_get();
        std::vector<Neuron*> neurons_get();

    private:
        std::vector<Neuron*> neurons_;
        size_t size_;
};

class MLP {
    public:
        MLP();
        void add_layer(size_t size, enum neuron_type type=STEP_NEURON);
        std::vector<double> propagate(std::vector<double> inputs);

    private:
        std::list<Layer> layers_;
};

#endif /* !BRAIN_HH */
