#include "CSVOutput.h"
#include <fstream>
CSVOutput::CSVOutput(const std::string& filename) : filename(filename) {}
void CSVOutput::write(const SimulationResult& result) {
    std::ofstream file(filename);
    if (!file) return;
    file << "Inputs,Outputs\n";
    const auto& inputs = result.getInputs();
    const auto& outputs = result.getOutputs();
    for (size_t i = 0; i < inputs.size(); ++i) {
        file << inputs[i];
        if (i + 1 < inputs.size()) file << ",";
    }
    file << ",";
    for (size_t i = 0; i < outputs.size(); ++i) {
        file << outputs[i];
        if (i + 1 < outputs.size()) file << ",";
    }
    file << "\n";
}
