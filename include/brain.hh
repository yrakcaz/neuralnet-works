#ifndef BRAIN_HH
# define BRAIN_HH

# include "neuron.hh"

class Layer {
    public:
        Layer(size_t size, enum neuron_type type, size_t nb_inputs=1);

    private:
        std::vector<Neuron> neurons_;
};

class MLP {
    public:
        MLP();
        void add_layer(Layer layer);

    private:
        std::list<Layer> layers_;
};

#endif /* !BRAIN_HH */
