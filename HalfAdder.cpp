#include "HalfAdder.h"

HalfAdder::HalfAdder()
    : Circuit("Half Adder"),
      sumWire(this, nullptr),
      carryWire(this, nullptr)
{
}

SimulationResult HalfAdder::simulate(
    const std::vector<int>& inputs)
{
    int A = inputs[0];
    int B = inputs[1];

    // XOR produces SUM
    int sum = xorGate.evaluate(A, B);
    sumWire.setSignal(sum);

    // AND produces CARRY
    int carry = andGate.evaluate(A, B);
    carryWire.setSignal(carry);

    std::vector<int> outputs = {
        sumWire.getSignal(),
        carryWire.getSignal()
    };

    return SimulationResult(inputs, outputs);
}