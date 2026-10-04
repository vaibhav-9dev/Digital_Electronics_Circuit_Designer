#include "Encoder.h"

Encoder::Encoder()
    : Circuit("4:2 Encoder"),
      y1Wire(&y1Gate, this),
      y0Wire(&y0Gate, this)
{
}

SimulationResult Encoder::simulate(const std::vector<int>& inputs)
{
    int D0 = inputs[0];
    int D1 = inputs[1];
    int D2 = inputs[2];
    int D3 = inputs[3];

    // Standard 4-to-2 one-hot encoder:
    // Y1 = D2 + D3, Y0 = D1 + D3
    int y1 = y1Gate.evaluate({D2, D3});
    int y0 = y0Gate.evaluate({D1, D3});

    y1Wire.setSignal(y1);
    y0Wire.setSignal(y0);

    return SimulationResult(inputs, {y1Wire.getSignal(), y0Wire.getSignal()});
}
