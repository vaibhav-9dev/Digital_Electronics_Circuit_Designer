#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "Component.h"
#include "SimulationResult.h"
#include <vector>
class Circuit : public Component {
public:
    Circuit(const std::string& name) : Component(name) {}
    virtual ~Circuit() = default;
    virtual SimulationResult simulate(const std::vector<int>& inputs) = 0;
};
#endif
