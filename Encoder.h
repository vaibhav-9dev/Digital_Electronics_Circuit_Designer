#ifndef ENCODER_H
#define ENCODER_H

#include "Circuit.h"
#include "Or.h"
#include "Wire.h"

class Encoder : public Circuit
{
private:
    OR y1Gate;
    OR y0Gate;
    Wire y1Wire;
    Wire y0Wire;

public:
    Encoder();
    SimulationResult simulate(const std::vector<int>& inputs) override;
};

#endif
