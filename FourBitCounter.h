#ifndef FOURBITCOUNTER_H
#define FOURBITCOUNTER_H
#include "Circuit.h"
#include "FullAdder.h"
#include <vector>
class FourBitCounter : public Circuit {
private:
    std::vector<int> state;
    FullAdder fullAdders[4];
public:
    FourBitCounter();
    void tick();
    void reset();
    std::vector<int> getState() const;
    void setState(const std::vector<int>& newState);
    SimulationResult simulate(const std::vector<int>& inputs) override;
};
#endif
