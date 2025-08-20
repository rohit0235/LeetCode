#include <vector>
#include <algorithm>

class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        std::vector<std::vector<int>> dp = mat;

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (dp[i][j] == 1) {
                    dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                count += dp[i][j];
            }
        }

        return count;
    }
};