#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

class Solution {
public:
    bool backtrack(std::vector<double>& cards) {
        if (cards.size() == 1) {
            return std::abs(cards[0] - 24.0) < 1e-9;
        }

        for (int i = 0; i < cards.size(); ++i) {
            for (int j = i + 1; j < cards.size(); ++j) {
                std::vector<double> nextCards;
                for (int k = 0; k < cards.size(); ++k) {
                    if (k != i && k != j) {
                        nextCards.push_back(cards[k]);
                    }
                }

                double a = cards[i];
                double b = cards[j];

                // Addition
                nextCards.push_back(a + b);
                if (backtrack(nextCards)) return true;
                nextCards.pop_back();

                // Subtraction (a - b and b - a)
                nextCards.push_back(a - b);
                if (backtrack(nextCards)) return true;
                nextCards.pop_back();

                nextCards.push_back(b - a);
                if (backtrack(nextCards)) return true;
                nextCards.pop_back();

                // Multiplication
                nextCards.push_back(a * b);
                if (backtrack(nextCards)) return true;
                nextCards.pop_back();

                // Division (a / b and b / a)
                if (b != 0) {
                    nextCards.push_back(a / b);
                    if (backtrack(nextCards)) return true;
                    nextCards.pop_back();
                }

                if (a != 0) {
                    nextCards.push_back(b / a);
                    if (backtrack(nextCards)) return true;
                    nextCards.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(std::vector<int>& cards_int) {
        std::vector<double> cards(cards_int.begin(), cards_int.end());
        return backtrack(cards);
    }
};