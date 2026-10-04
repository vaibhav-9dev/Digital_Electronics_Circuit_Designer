#include "SimulationResult.h"
SimulationResult::SimulationResult() {}
SimulationResult::SimulationResult(const std::vector<int>& inputs,
                                   const std::vector<int>& outputs)
    : inputs(inputs), outputs(outputs) {}
const std::vector<int>& SimulationResult::getInputs() const { return inputs; }
const std::vector<int>& SimulationResult::getOutputs() const { return outputs; }
void SimulationResult::setInputs(const std::vector<int>& inputs) { this->inputs = inputs; }
void SimulationResult::setOutputs(const std::vector<int>& outputs) { this->outputs = outputs; }
