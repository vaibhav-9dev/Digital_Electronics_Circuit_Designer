#ifndef NOR_H
#define NOR_H
#include "Gate.h"
class NOR : public Gate {
public:
    using Gate::evaluate;
    NOR();
    int evaluate(const std::vector<int>& inputs) override;
};
#endif
