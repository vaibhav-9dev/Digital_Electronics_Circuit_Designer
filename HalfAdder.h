#ifndef HALFADDER_H
#define HALFADDER_H

#include "Circuit.h"
#include "Xor.h"
#include "And.h"
#include "Wire.h"

class HalfAdder : public Circuit
{
private:
    XOR xorGate;
    AND andGate;

    Wire sumWire;
    Wire carryWire;

public:
    HalfAdder();

    SimulationResult simulate(
        const std::vector<int>& inputs
    ) override;
};

#endif