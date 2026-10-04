#include "Nor.h"
NOR::NOR() : Gate("NOR") {}
int NOR::evaluate(const std::vector<int>& inputs) {
    return !(inputs[0] || inputs[1]);
}
