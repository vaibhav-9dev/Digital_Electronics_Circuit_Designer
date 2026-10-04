#ifndef FOURBITADDER_H
#define FOURBITADDER_H

#include "Circuit.h"
#include "FullAdder.h"

class FourBitAdder : public Circuit
{
private:
    FullAdder fullAdders[4];

public:
    FourBitAdder();

    SimulationResult simulate(
        const std::vector<int>& inputs
    ) override;

    void displayCircuit(
        const std::vector<int>& inputs,
        int cin = 0
    ) const;
};

#endif