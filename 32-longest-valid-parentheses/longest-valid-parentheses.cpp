#include <string>
#include <algorithm> // For std::max

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }

        int maxLen = 0;
        int open = 0;
        int close = 0;

        // First pass: Left to right
        // This pass correctly identifies valid parentheses sequences that
        // are balanced or have an excess of '('.
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                open++;
            } else { // s[i] == ')'
                close++;
            }

            if (open == close) {
                // If balanced, update maxLen
                maxLen = std::max(maxLen, 2 * open);
            } else if (close > open) {
                // If more ')' than '(', it's an invalid sequence from this point.
                // Reset counts and start fresh.
                open = 0;
                close = 0;
            }
            // If open > close, do nothing, continue to find a matching ')'
        }

        // Reset counts for the second pass
        open = 0;
        close = 0;

        // Second pass: Right to left
        // This pass handles cases where the string might have an excess of
        // '(' on the left, which the first pass couldn't catch.
        // E.g., for "(()", the first pass gives 2. The second pass will correctly capture it.
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                open++;
            } else { // s[i] == ')'
                close++;
            }

            if (open == close) {
                // If balanced, update maxLen
                maxLen = std::max(maxLen, 2 * open);
            } else if (open > close) {
                // If more '(' than ')', it's an invalid sequence from this point.
                // Reset counts and start fresh.
                open = 0;
                close = 0;
            }
            // If close > open, do nothing, continue to find a matching '('
        }

        return maxLen;
    }
};