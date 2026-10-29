#ifndef CIRCUITSTORAGE_H
#define CIRCUITSTORAGE_H

#include <string>
#include <vector>

class CircuitStorage
{
public:
    static bool save(
        const std::string& filename,
        const std::string& circuitType,
        const std::vector<int>& inputs,
        const std::vector<int>& outputs = {},
        const std::vector<int>& state = {}
    );

    static bool load(
        const std::string& filename,
        std::string& circuitType,
        std::vector<int>& inputs,
        std::vector<int>& outputs,
        std::vector<int>& state
    );

private:
    static std::string bitsToString(const std::vector<int>& bits);
    static std::vector<int> stringToBits(const std::string& value);
};

#endif
