#ifndef SIMULATIONRESULT_H
#define SIMULATIONRESULT_H
#include <vector>
class SimulationResult {
private:
    std::vector<int> inputs, outputs;
public:
    SimulationResult();
    SimulationResult(const std::vector<int>& inputs,
                     const std::vector<int>& outputs);
    const std::vector<int>& getInputs() const;
    const std::vector<int>& getOutputs() const;
    void setInputs(const std::vector<int>& inputs);
    void setOutputs(const std::vector<int>& outputs);
};
#endif
