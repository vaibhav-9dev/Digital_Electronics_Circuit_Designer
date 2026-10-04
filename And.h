#ifndef AND_H
#define AND_H
#include "Gate.h"
#include "Nand.h"
#include "Not.h"
class AND : public Gate {
private:
    NAND nandGate;
    NOT notGate;
public:
    using Gate::evaluate;
    AND();
    int evaluate(const std::vector<int>& inputs) override;
};
#endif
