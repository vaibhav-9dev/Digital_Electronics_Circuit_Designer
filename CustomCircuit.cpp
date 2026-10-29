#include "CustomCircuit.h"
#include "And.h"
#include "Not.h"
#include "Or.h"

#include <iostream>
#include <stdexcept>

using namespace std;

CustomCircuit::CustomCircuit(const string& circuitName,
                             const vector<string>& variableNames,
                             const vector<Implicant>& minimizedTerms)
    : Circuit(circuitName), variableNames_(variableNames), outputNodeIndex_(-1) {
    if (variableNames_.empty() || variableNames_.size() > 6) {
        throw invalid_argument("CustomCircuit supports 1 to 6 input variables.");
    }
    buildNetwork(minimizedTerms);
}

int CustomCircuit::addNode(NodeType type, int inputIndex, int constantValue,
                           int left, int right) {
    GateNode node;
    node.type = type;
    node.inputIndex = inputIndex;
    node.constantValue = constantValue;
    node.left = left;
    node.right = right;
    nodes_.push_back(node);
    return static_cast<int>(nodes_.size()) - 1;
}

int CustomCircuit::addConstant(int value) {
    return addNode(CONSTANT_NODE, -1, value, -1, -1);
}

void CustomCircuit::buildNetwork(const vector<Implicant>& minimizedTerms) {
    inputNodeIndices_.clear();
    vector<int> notNodeIndices(variableNames_.size(), -1);

    // Input nodes are always created first, making references easy to read.
    for (size_t i = 0; i < variableNames_.size(); ++i) {
        inputNodeIndices_.push_back(addNode(INPUT_NODE, static_cast<int>(i)));
    }

    if (minimizedTerms.empty()) {
        outputNodeIndex_ = addConstant(0);
        return;
    }

    vector<int> productOutputs;
    for (const Implicant& term : minimizedTerms) {
        vector<int> literalNodes;
        for (size_t i = 0; i < term.pattern.size(); ++i) {
            if (term.pattern[i] == '-') continue;
            if (term.pattern[i] == '1') {
                literalNodes.push_back(inputNodeIndices_[i]);
            } else {
                if (notNodeIndices[i] == -1) {
                    notNodeIndices[i] = addNode(NOT_NODE, -1, 0,
                                                inputNodeIndices_[i], -1);
                }
                literalNodes.push_back(notNodeIndices[i]);
            }
        }

        if (literalNodes.empty()) {
            productOutputs.push_back(addConstant(1));
            break; // A constant 1 term makes the entire SOP equal to 1.
        }

        int product = literalNodes[0];
        for (size_t i = 1; i < literalNodes.size(); ++i) {
            product = addNode(AND_NODE, -1, 0, product, literalNodes[i]);
        }
        productOutputs.push_back(product);
    }

    if (productOutputs.empty()) {
        outputNodeIndex_ = addConstant(0);
        return;
    }

    int result = productOutputs[0];
    for (size_t i = 1; i < productOutputs.size(); ++i) {
        result = addNode(OR_NODE, -1, 0, result, productOutputs[i]);
    }
    outputNodeIndex_ = result;
}

SimulationResult CustomCircuit::simulate(const vector<int>& inputs) {
    if (inputs.size() != variableNames_.size()) {
        throw invalid_argument("The number of input values does not match the circuit.");
    }
    for (int value : inputs) {
        if (value != 0 && value != 1) {
            throw invalid_argument("Circuit inputs must be 0 or 1.");
        }
    }

    AND andGate;
    OR orGate;
    NOT notGate;
    vector<int> values(nodes_.size(), 0);

    // Nodes are in topological order: a gate's inputs are evaluated first.
    for (size_t i = 0; i < nodes_.size(); ++i) {
        const GateNode& node = nodes_[i];
        switch (node.type) {
            case INPUT_NODE:
                values[i] = inputs[node.inputIndex];
                break;
            case CONSTANT_NODE:
                values[i] = node.constantValue;
                break;
            case NOT_NODE:
                values[i] = notGate.evaluate(values[node.left]);
                break;
            case AND_NODE:
                values[i] = andGate.evaluate(values[node.left], values[node.right]);
                break;
            case OR_NODE:
                values[i] = orGate.evaluate(values[node.left], values[node.right]);
                break;
        }
    }

    return SimulationResult(inputs, vector<int>{values[outputNodeIndex_]});
}

void CustomCircuit::printGateNetwork(ostream& output) const {
    output << "\n========== GENERATED GATE NETWORK ==========\n";
    for (size_t i = 0; i < nodes_.size(); ++i) {
        const GateNode& node = nodes_[i];
        output << "v" << i << " = ";
        switch (node.type) {
            case INPUT_NODE:
                output << "INPUT " << variableNames_[node.inputIndex];
                break;
            case CONSTANT_NODE:
                output << "CONST " << node.constantValue;
                break;
            case NOT_NODE:
                output << "NOT(v" << node.left << ")";
                break;
            case AND_NODE:
                output << "AND(v" << node.left << ", v" << node.right << ")";
                break;
            case OR_NODE:
                output << "OR(v" << node.left << ", v" << node.right << ")";
                break;
        }
        output << '\n';
    }
    output << "Output Y = v" << outputNodeIndex_ << '\n';
    output << "============================================\n";
}

const vector<string>& CustomCircuit::getVariableNames() const {
    return variableNames_;
}
