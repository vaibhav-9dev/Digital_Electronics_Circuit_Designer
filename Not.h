#ifndef NOT_H
#define NOT_H
#include "Gate.h"
#include "Nand.h"
class NOT : public Gate {
private:
    NAND nandGate;
public:
    using Gate::evaluate;
    NOT();
    int evaluate(const std::vector<int>& inputs) override;
};
#endif
