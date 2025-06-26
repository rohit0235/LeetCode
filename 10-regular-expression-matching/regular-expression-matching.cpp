#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        // dp[i][j] will be true if s[0...i-1] matches p[0...j-1]
        // We use (n+1) and (m+1) for indexing ease,
        // where dp[i][j] corresponds to s.substr(0, i) and p.substr(0, j)
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));

        // Base case: An empty string matches an empty pattern
        dp[0][0] = true;

        // Populate the first row: s is empty, p is not
        // Only patterns like "a*", "a*b*", ".*" can match an empty string
        for (int j = 1; j <= m; ++j) {
            // If the current pattern character is '*' and the character before it exists
            if (p[j - 1] == '*') {
                // If the pattern character before '*' is valid (i.e., j-1 > 0 means p[j-2] exists)
                // then dp[0][j] depends on dp[0][j-2] (zero occurrences of p[j-2])
                // Example: "" matches "a*", because "a*" can mean ""
                if (j > 1) { // Ensure p[j-2] is valid
                    dp[0][j] = dp[0][j - 2];
                }
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // Case 1: Current pattern character is a literal or '.'
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // If previous parts matched, then current parts match
                }
                // Case 2: Current pattern character is '*'
                else if (p[j - 1] == '*') {
                    // Check for zero occurrences of the character preceding '*'
                    // If p[j-2]* can match s[0...i-1] by having zero occurrences
                    // then dp[i][j] is true if dp[i][j-2] is true
                    // (i.e., s[0...i-1] matched p[0...j-3])
                    dp[i][j] = dp[i][j - 2];

                    // Check for one or more occurrences of the character preceding '*'
                    // If p[j-2] matches s[i-1] (or p[j-2] is '.'),
                    // then '*' can potentially match s[i-1].
                    // In this case, dp[i][j] is also true if dp[i-1][j] is true.
                    // (i.e., s[0...i-2] matched p[0...j-1], and s[i-1] is another match for p[j-2])
                    if (j > 1 && (p[j - 2] == '.' || p[j - 2] == s[i - 1])) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
           // Case 3: Current pattern character is a literal, but it doesn't match s[i-1]
                // (and it's not '.' or '*')
                // In this case, dp[i][j] remains false (initialized value)
            }
        }

        return dp[n][m];
    }
};