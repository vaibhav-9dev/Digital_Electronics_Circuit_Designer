#ifndef XOR_H
#define XOR_H
#include "Gate.h"
#include "Nand.h"
class XOR : public Gate {
private:
    NAND nand1, nand2, nand3, nand4;
public:
    using Gate::evaluate;
    XOR();
    int evaluate(const std::vector<int>& inputs) override;
};
#endif
