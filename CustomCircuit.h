#ifndef CUSTOM_CIRCUIT_H
#define CUSTOM_CIRCUIT_H

#include "Circuit.h"
#include "BooleanMinimizer.h"
#include <iosfwd>
#include <string>
#include <vector>

class CustomCircuit : public Circuit {
public:
    CustomCircuit(const std::string& circuitName,
                  const std::vector<std::string>& variableNames,
                  const std::vector<Implicant>& minimizedTerms);

    SimulationResult simulate(const std::vector<int>& inputs) override;
    void printGateNetwork(std::ostream& output) const;
    const std::vector<std::string>& getVariableNames() const;

private:
    enum NodeType { INPUT_NODE, CONSTANT_NODE, NOT_NODE, AND_NODE, OR_NODE };

    struct GateNode {
        NodeType type;
        int inputIndex;
        int constantValue;
        int left;
        int right;
    };

    std::vector<std::string> variableNames_;
    std::vector<GateNode> nodes_;
    std::vector<int> inputNodeIndices_;
    int outputNodeIndex_;

    int addNode(NodeType type, int inputIndex = -1, int constantValue = 0,
                int left = -1, int right = -1);
    int addConstant(int value);
    void buildNetwork(const std::vector<Implicant>& minimizedTerms);
};

#endif
