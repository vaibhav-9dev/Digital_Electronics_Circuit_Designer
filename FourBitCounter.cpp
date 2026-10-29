#include "FourBitCounter.h"
FourBitCounter::FourBitCounter() : Circuit("4-Bit Counter"), state(4, 0) {}
void FourBitCounter::tick() {
    int carry = 1;
    for (int i = 0; i < 4; ++i) {
        SimulationResult r = fullAdders[i].simulate({state[i], 0, carry});
        state[i] = r.getOutputs()[0];
        carry = r.getOutputs()[1];
    }
}
void FourBitCounter::reset() { state.assign(4, 0); }
std::vector<int> FourBitCounter::getState() const { return state; }

void FourBitCounter::setState(const std::vector<int>& newState)
{
    if (newState.size() == 4)
        state = newState;
}
SimulationResult FourBitCounter::simulate(const std::vector<int>& inputs) {
    if (!inputs.empty() && inputs[0] == 1) tick();
    return SimulationResult(inputs, state);
}
