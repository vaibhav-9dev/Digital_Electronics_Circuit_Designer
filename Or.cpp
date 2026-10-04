#include "Or.h"
OR::OR() : Gate("OR") {}
int OR::evaluate(const std::vector<int>& inputs) {
    int norOutput = norGate.evaluate(inputs[0], inputs[1]);
    return notGate.evaluate(norOutput);
}
