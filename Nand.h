#ifndef NAND_H
#define NAND_H
#include "Gate.h"
class NAND : public Gate {
public:
    using Gate::evaluate;
    NAND();
    int evaluate(const std::vector<int>& inputs) override;
};
#endif
