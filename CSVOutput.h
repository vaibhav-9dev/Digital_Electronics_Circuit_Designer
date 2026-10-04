#ifndef CSVOUTPUT_H
#define CSVOUTPUT_H
#include "Output.h"
#include <string>
class CSVOutput : public Output {
private:
    std::string filename;
public:
    CSVOutput(const std::string& filename);
    void write(const SimulationResult& result) override;
};
#endif
