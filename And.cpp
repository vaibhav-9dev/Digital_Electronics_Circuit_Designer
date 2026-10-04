#include "And.h"
AND::AND() : Gate("AND") {}
int AND::evaluate(const std::vector<int>& inputs) {
    int nandOutput = nandGate.evaluate(inputs[0], inputs[1]);
    return notGate.evaluate(nandOutput);
}
