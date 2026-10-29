#include "FullAdder.h"

FullAdder::FullAdder()
    : Circuit("Full Adder"),
      sumWire(&halfAdder1, &halfAdder2),
      carryWire1(&halfAdder1, &orGate),
      carryWire2(&halfAdder2, &orGate),
      outputWire(&orGate, this)
{
}

SimulationResult FullAdder::simulate(
    const std::vector<int>& inputs)
{
    int A   = inputs[0];
    int B   = inputs[1];
    int Cin = inputs[2];

    // First Half Adder
    SimulationResult result1 =
        halfAdder1.simulate({A, B});

    int sum1 = result1.getOutputs()[0];
    int carry1 = result1.getOutputs()[1];

    // Wire: HalfAdder 1 -> HalfAdder 2
    sumWire.setSignal(sum1);

    // Second Half Adder
    SimulationResult result2 =
        halfAdder2.simulate({
            sumWire.getSignal(),
            Cin
        });

    int sum = result2.getOutputs()[0];
    int carry2 = result2.getOutputs()[1];

    // Wires: HalfAdders -> OR gate
    carryWire1.setSignal(carry1);
    carryWire2.setSignal(carry2);

    int cout =
        orGate.evaluate(
            carryWire1.getSignal(),
            carryWire2.getSignal()
        );

    // OR -> FullAdder output
    outputWire.setSignal(cout);

    return SimulationResult(
        inputs,
        {sum, outputWire.getSignal()}
    );
}