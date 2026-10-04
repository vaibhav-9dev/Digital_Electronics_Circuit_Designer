#include "Decoder.h"

Decoder::Decoder()
    : Circuit("2:4 Decoder"),
      notAWire(&notA, &y0Gate),
      notBWire(&notB, &y0Gate),
      outputWires{
          Wire(&y0Gate, this),
          Wire(&y1Gate, this),
          Wire(&y2Gate, this),
          Wire(&y3Gate, this)
      }
{
}

SimulationResult Decoder::simulate(const std::vector<int>& inputs)
{
    int A = inputs[0];
    int B = inputs[1];

    notAWire.setSignal(notA.evaluate(A));
    notBWire.setSignal(notB.evaluate(B));

    int y0 = y0Gate.evaluate(notAWire.getSignal(), notBWire.getSignal());
    int y1 = y1Gate.evaluate(notAWire.getSignal(), B);
    int y2 = y2Gate.evaluate(A, notBWire.getSignal());
    int y3 = y3Gate.evaluate(A, B);

    outputWires[0].setSignal(y0);
    outputWires[1].setSignal(y1);
    outputWires[2].setSignal(y2);
    outputWires[3].setSignal(y3);

    return SimulationResult(inputs, {
        outputWires[0].getSignal(),
        outputWires[1].getSignal(),
        outputWires[2].getSignal(),
        outputWires[3].getSignal()
    });
}
