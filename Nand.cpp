#include "Nand.h"
NAND::NAND() : Gate("NAND") {}
int NAND::evaluate(const std::vector<int>& inputs) {
    return !(inputs[0] && inputs[1]);
}
