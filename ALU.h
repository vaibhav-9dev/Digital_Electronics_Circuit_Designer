#ifndef ALU_H
#define ALU_H

#include "Circuit.h"
#include "FourBitAdder.h"
#include "And.h"
#include "Xor.h"

// 4-bit ALU operation selector:
// 00 = Addition, 01 = Subtraction, 10 = Bitwise AND, 11 = Bitwise XOR
// Inputs: A3 A2 A1 A0 B3 B2 B1 B0 S1 S0
// Outputs: R3 R2 R1 R0 Flag
// Addition Flag = carry-out; Subtraction Flag = borrow; logical Flag = 0.
class ALU : public Circuit
{
private:
    FourBitAdder adder;
    AND andGate;
    XOR xorGate;

public:
    ALU();
    SimulationResult simulate(const std::vector<int>& inputs) override;
};

#endif
