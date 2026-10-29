#include "Xor.h"
XOR::XOR() : Gate("XOR") {}
int XOR::evaluate(const std::vector<int>& inputs) {
    int a = inputs[0], b = inputs[1];
    int x = nand1.evaluate(a, b);
    int y = nand2.evaluate(a, x);
    int z = nand3.evaluate(b, x);
    return nand4.evaluate(y, z);
}
