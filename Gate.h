#ifndef GATE_H
#define GATE_H
#include "Component.h"
#include <vector>
class Gate : public Component {
public:
    Gate(const std::string& name) : Component(name) {}
    virtual ~Gate() = default;
    virtual int evaluate(const std::vector<int>& inputs) = 0;
    int evaluate(int a, int b) { return evaluate(std::vector<int>{a, b}); }
    int evaluate(int a) { return evaluate(std::vector<int>{a}); }
};
#endif
