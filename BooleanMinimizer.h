#ifndef BOOLEAN_MINIMIZER_H
#define BOOLEAN_MINIMIZER_H

#include <cstdint>
#include <string>
#include <vector>

// A product term in a minimized SOP expression.
// '0' means a complemented variable, '1' means an uncomplemented variable,
// and '-' means that the variable is absent from the product term.
struct Implicant {
    std::string pattern;
    std::uint64_t coveredMinterms;

    int literalCount() const;
};

class BooleanMinimizer {
public:
    // Truth-table rows are ordered as binary numbers, with the first variable
    // as the most-significant bit. Output values must be 0 or 1.
    static std::string canonicalSOP(
        const std::vector<std::string>& variableNames,
        const std::vector<int>& outputValues);

    // Exact Quine-McCluskey minimization for up to 6 input variables.
    static std::vector<Implicant> minimizeSOP(
        const std::vector<std::string>& variableNames,
        const std::vector<int>& outputValues);

    static std::string minimizedSOP(
        const std::vector<std::string>& variableNames,
        const std::vector<Implicant>& implicants);
};

#endif
