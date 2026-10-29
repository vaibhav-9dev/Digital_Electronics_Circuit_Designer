#ifndef OR_H
#define OR_H
#include "Gate.h"
#include "Nor.h"
#include "Not.h"
class OR : public Gate {
private:
    NOR norGate;
    NOT notGate;
public:
    using Gate::evaluate;
    OR();
    int evaluate(const std::vector<int>& inputs) override;
};
#endif
