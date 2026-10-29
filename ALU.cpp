#include "ALU.h"
#include <stdexcept>

ALU::ALU() : Circuit("4-Bit ALU") {}

SimulationResult ALU::simulate(const std::vector<int>& inputs)
{
    if (inputs.size() != 10)
        throw std::invalid_argument("4-bit ALU requires 10 inputs: A[4], B[4], S1, S0.");

    for (int bit : inputs)
        if (bit != 0 && bit != 1)
            throw std::invalid_argument("4-bit ALU inputs must be 0 or 1.");

    const int s1 = inputs[8];
    const int s0 = inputs[9];
    const int operation = (s1 << 1) | s0;
    std::vector<int> outputs(5, 0); // R3 R2 R1 R0 Flag

    if (operation == 0 || operation == 1)
    {
        // Addition: A + B + 0
        // Subtraction: A + (~B) + 1 (two's complement)
        std::vector<int> adderInputs(inputs.begin(), inputs.begin() + 8);
        if (operation == 1)
        {
            for (int i = 4; i < 8; ++i)
                adderInputs[i] = 1 - adderInputs[i];
        }
        adderInputs.push_back(operation == 1 ? 1 : 0);

        SimulationResult sumResult = adder.simulate(adderInputs);
        const auto& sumOutputs = sumResult.getOutputs(); // S3 S2 S1 S0 C4
        for (int i = 0; i < 4; ++i)
            outputs[i] = sumOutputs[i];

        if (operation == 0)
            outputs[4] = sumOutputs[4]; // carry-out
        else
            outputs[4] = 1 - sumOutputs[4]; // borrow = NOT carry-out
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            const int a = inputs[i];
            const int b = inputs[i + 4];
            outputs[i] = (operation == 2)
                ? andGate.evaluate(a, b)
                : xorGate.evaluate(a, b);
        }
        outputs[4] = 0;
    }

    return SimulationResult(inputs, outputs);
}
