#include "Not.h"
NOT::NOT() : Gate("NOT") {}
int NOT::evaluate(const std::vector<int>& inputs) {
    return nandGate.evaluate(inputs[0], inputs[0]);
}
