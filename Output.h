#ifndef OUTPUT_H
#define OUTPUT_H
#include "SimulationResult.h"
class Output {
public:
    virtual ~Output() = default;
    virtual void write(const SimulationResult& result) = 0;
};
#endif
