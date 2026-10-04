#include "Mux.h"

MUX::MUX()
    : Circuit("2:1 Multiplexer"),
      notSelectWire(&notGate, &andI0),
      path0Wire(&andI0, &orGate),
      path1Wire(&andI1, &orGate),
      outputWire(&orGate, this)
{
}

SimulationResult MUX::simulate(const std::vector<int>& inputs)
{
    int I0 = inputs[0];
    int I1 = inputs[1];
    int S  = inputs[2];

    int notS = notGate.evaluate(S);
    notSelectWire.setSignal(notS);

    path0Wire.setSignal(andI0.evaluate(I0, notSelectWire.getSignal()));
    path1Wire.setSignal(andI1.evaluate(I1, S));
    outputWire.setSignal(orGate.evaluate(path0Wire.getSignal(), path1Wire.getSignal()));

    return SimulationResult(inputs, {outputWire.getSignal()});
}
