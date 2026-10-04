#include "CircuitStorage.h"
#include <fstream>
#include <sstream>

std::string CircuitStorage::bitsToString(const std::vector<int>& bits)
{
    std::string result;
    for (int bit : bits)
        result += (bit == 0 ? '0' : '1');
    return result;
}

std::vector<int> CircuitStorage::stringToBits(const std::string& value)
{
    std::vector<int> bits;
    for (char c : value)
    {
        if (c == '0' || c == '1')
            bits.push_back(c - '0');
    }
    return bits;
}

bool CircuitStorage::save(
    const std::string& filename,
    const std::string& circuitType,
    const std::vector<int>& inputs,
    const std::vector<int>& outputs,
    const std::vector<int>& state)
{
    std::ofstream file(filename);

    if (!file)
        return false;

    file << "Field,Value\n";
    file << "CircuitType," << circuitType << "\n";
    file << "Inputs," << bitsToString(inputs) << "\n";
    file << "Outputs," << bitsToString(outputs) << "\n";
    file << "State," << bitsToString(state) << "\n";

    return true;
}

bool CircuitStorage::load(
    const std::string& filename,
    std::string& circuitType,
    std::vector<int>& inputs,
    std::vector<int>& outputs,
    std::vector<int>& state)
{
    std::ifstream file(filename);

    if (!file)
        return false;

    circuitType.clear();
    inputs.clear();
    outputs.clear();
    state.clear();

    std::string line;

    // Skip CSV header.
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string field;
        std::string value;

        std::getline(ss, field, ',');
        std::getline(ss, value);

        if (field == "CircuitType")
            circuitType = value;
        else if (field == "Inputs")
            inputs = stringToBits(value);
        else if (field == "Outputs")
            outputs = stringToBits(value);
        else if (field == "State")
            state = stringToBits(value);
    }

    return !circuitType.empty();
}
