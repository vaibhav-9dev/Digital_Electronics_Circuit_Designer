#ifndef FULLADDER_H
#define FULLADDER_H

#include "Circuit.h"
#include "HalfAdder.h"
#include "Or.h"
#include "Wire.h"

class FullAdder : public Circuit
{
private:
    HalfAdder halfAdder1;
    HalfAdder halfAdder2;

    OR orGate;

    Wire sumWire;
    Wire carryWire1;
    Wire carryWire2;
    Wire outputWire;

public:
    FullAdder();

    SimulationResult simulate(
        const std::vector<int>& inputs
    ) override;
};

#endif