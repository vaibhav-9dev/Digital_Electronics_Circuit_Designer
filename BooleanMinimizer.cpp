#include "BooleanMinimizer.h"

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <stdexcept>

using namespace std;

int Implicant::literalCount() const {
    int count = 0;
    for (char bit : pattern) {
        if (bit != '-') ++count;
    }
    return count;
}

namespace {
struct Cube {
    string pattern;
    uint64_t coveredMinterms;
    bool combined;
};

string rowPattern(size_t row, size_t numberOfVariables) {
    string pattern(numberOfVariables, '0');
    for (size_t i = 0; i < numberOfVariables; ++i) {
        size_t shift = numberOfVariables - 1 - i;
        pattern[i] = ((row >> shift) & 1U) ? '1' : '0';
    }
    return pattern;
}

bool combinePatterns(const string& a, const string& b, string& combined) {
    int differences = 0;
    combined = a;

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == b[i]) continue;
        // A dash must be in the same position in both cubes.
        if (a[i] == '-' || b[i] == '-') return false;
        ++differences;
        combined[i] = '-';
        if (differences > 1) return false;
    }
    return differences == 1;
}

string productTerm(const string& pattern,
                   const vector<string>& variableNames) {
    string term;
    for (size_t i = 0; i < pattern.size(); ++i) {
        if (pattern[i] == '-') continue;
        if (!term.empty()) term += "*";
        if (pattern[i] == '0') term += "!";
        term += variableNames[i];
    }
    return term.empty() ? "1" : term;
}

uint64_t targetMaskFromOutputs(const vector<int>& outputValues) {
    uint64_t mask = 0;
    for (size_t i = 0; i < outputValues.size(); ++i) {
        if (outputValues[i] == 1) mask |= (uint64_t(1) << i);
    }
    return mask;
}

bool isAllDash(const string& pattern) {
    return pattern.find_first_not_of('-') == string::npos;
}

int countSetBits(uint64_t value) {
    int count = 0;
    while (value != 0) {
        value &= (value - 1);
        ++count;
    }
    return count;
}

vector<Implicant> selectMinimumCover(const vector<Implicant>& primes,
                                     uint64_t targetMask) {
    if (targetMask == 0) return {};

    vector<int> bestSelection;
    vector<int> currentSelection;
    vector<bool> selected(primes.size(), false);
    int bestTerms = INT_MAX;
    int bestLiterals = INT_MAX;

    function<void(uint64_t, int)> search = [&](uint64_t covered, int literals) {
        if ((covered & targetMask) == targetMask) {
            if (static_cast<int>(currentSelection.size()) < bestTerms ||
                (static_cast<int>(currentSelection.size()) == bestTerms &&
                 literals < bestLiterals)) {
                bestTerms = static_cast<int>(currentSelection.size());
                bestLiterals = literals;
                bestSelection = currentSelection;
            }
            return;
        }

        if (static_cast<int>(currentSelection.size()) >= bestTerms) return;

        uint64_t uncovered = targetMask & ~covered;
        int chosenMinterm = -1;
        size_t fewestChoices = static_cast<size_t>(-1);

        // Choose the uncovered minterm with the fewest prime-implicant choices.
        for (int bit = 0; bit < 64; ++bit) {
            if ((uncovered & (uint64_t(1) << bit)) == 0) continue;
            size_t choices = 0;
            for (size_t p = 0; p < primes.size(); ++p) {
                if (!selected[p] &&
                    (primes[p].coveredMinterms & (uint64_t(1) << bit))) {
                    ++choices;
                }
            }
            if (choices < fewestChoices) {
                fewestChoices = choices;
                chosenMinterm = bit;
                if (choices <= 1) break;
            }
        }

        if (chosenMinterm < 0 || fewestChoices == 0) return;

        vector<int> candidates;
        for (size_t p = 0; p < primes.size(); ++p) {
            if (!selected[p] &&
                (primes[p].coveredMinterms & (uint64_t(1) << chosenMinterm))) {
                candidates.push_back(static_cast<int>(p));
            }
        }

        // Try implicants that cover the most currently-uncovered minterms first.
        sort(candidates.begin(), candidates.end(), [&](int a, int b) {
            int coverA = countSetBits(primes[a].coveredMinterms & uncovered);
            int coverB = countSetBits(primes[b].coveredMinterms & uncovered);
            if (coverA != coverB) return coverA > coverB;
            return primes[a].literalCount() < primes[b].literalCount();
        });

        for (int p : candidates) {
            selected[p] = true;
            currentSelection.push_back(p);
            search(covered | primes[p].coveredMinterms,
                   literals + primes[p].literalCount());
            currentSelection.pop_back();
            selected[p] = false;
        }
    };

    search(0, 0);

    vector<Implicant> result;
    for (int index : bestSelection) result.push_back(primes[index]);
    sort(result.begin(), result.end(), [](const Implicant& a, const Implicant& b) {
        return a.pattern < b.pattern;
    });
    return result;
}
} // namespace

string BooleanMinimizer::canonicalSOP(
    const vector<string>& variableNames,
    const vector<int>& outputValues) {
    if (outputValues.size() != (size_t(1) << variableNames.size())) {
        throw invalid_argument("Truth-table row count does not match the input count.");
    }

    vector<string> terms;
    for (size_t row = 0; row < outputValues.size(); ++row) {
        if (outputValues[row] != 1) continue;
        terms.push_back(productTerm(rowPattern(row, variableNames.size()), variableNames));
    }

    if (terms.empty()) return "0";
    for (const string& term : terms) {
        if (term == "1") return "1";
    }

    string expression;
    for (const string& term : terms) {
        if (!expression.empty()) expression += " + ";
        expression += term;
    }
    return expression;
}

vector<Implicant> BooleanMinimizer::minimizeSOP(
    const vector<string>& variableNames,
    const vector<int>& outputValues) {
    const size_t numberOfVariables = variableNames.size();
    if (numberOfVariables < 1 || numberOfVariables > 6) {
        throw invalid_argument("SOP minimization supports 1 to 6 input variables.");
    }
    if (outputValues.size() != (size_t(1) << numberOfVariables)) {
        throw invalid_argument("Truth-table row count does not match the input count.");
    }
    for (int value : outputValues) {
        if (value != 0 && value != 1) {
            throw invalid_argument("Truth-table outputs must be 0 or 1.");
        }
    }

    const uint64_t targetMask = targetMaskFromOutputs(outputValues);
    if (targetMask == 0) return {};

    vector<Cube> current;
    for (size_t row = 0; row < outputValues.size(); ++row) {
        if (outputValues[row] == 1) {
            current.push_back({rowPattern(row, numberOfVariables),
                               uint64_t(1) << row, false});
        }
    }

    map<string, uint64_t> primeMap;
    while (!current.empty()) {
        vector<Cube> next;
        map<string, uint64_t> nextMap;

        for (Cube& cube : current) cube.combined = false;

        for (size_t i = 0; i < current.size(); ++i) {
            for (size_t j = i + 1; j < current.size(); ++j) {
                string combinedPattern;
                if (combinePatterns(current[i].pattern, current[j].pattern,
                                    combinedPattern)) {
                    current[i].combined = true;
                    current[j].combined = true;
                    nextMap[combinedPattern] |= current[i].coveredMinterms |
                                               current[j].coveredMinterms;
                }
            }
        }

        for (const Cube& cube : current) {
            if (!cube.combined) {
                primeMap[cube.pattern] |= cube.coveredMinterms;
            }
        }

        for (const auto& item : nextMap) {
            next.push_back({item.first, item.second, false});
        }
        current.swap(next);
    }

    vector<Implicant> primes;
    for (const auto& item : primeMap) {
        primes.push_back({item.first, item.second});
    }

    return selectMinimumCover(primes, targetMask);
}

string BooleanMinimizer::minimizedSOP(
    const vector<string>& variableNames,
    const vector<Implicant>& implicants) {
    if (implicants.empty()) return "0";
    for (const Implicant& implicant : implicants) {
        if (isAllDash(implicant.pattern)) return "1";
    }

    string expression;
    for (const Implicant& implicant : implicants) {
        if (!expression.empty()) expression += " + ";
        expression += productTerm(implicant.pattern, variableNames);
    }
    return expression;
}
