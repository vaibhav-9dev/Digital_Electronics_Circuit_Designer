#ifndef DECODER_H
#define DECODER_H

#include "Circuit.h"
#include "Not.h"
#include "And.h"
#include "Wire.h"

class Decoder : public Circuit
{
private:
    NOT notA;
    NOT notB;
    AND y0Gate;
    AND y1Gate;
    AND y2Gate;
    AND y3Gate;

    Wire notAWire;
    Wire notBWire;
    Wire outputWires[4];

public:
    Decoder();
    SimulationResult simulate(const std::vector<int>& inputs) override;
};

#endif
