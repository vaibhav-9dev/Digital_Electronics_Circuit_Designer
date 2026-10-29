#ifndef MUX_H
#define MUX_H

#include "Circuit.h"
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "Wire.h"

class MUX : public Circuit
{
private:
    NOT notGate;
    AND andI0;
    AND andI1;
    OR orGate;

    Wire notSelectWire;
    Wire path0Wire;
    Wire path1Wire;
    Wire outputWire;

public:
    MUX();
    SimulationResult simulate(const std::vector<int>& inputs) override;
};

#endif
