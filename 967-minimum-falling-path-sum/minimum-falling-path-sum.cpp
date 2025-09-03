

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int minAbove = matrix[i-1][j];
                if (j > 0) {
                    minAbove =min(minAbove, matrix[i-1][j-1]);
                }
                if (j < m - 1) {
                    minAbove =min(minAbove, matrix[i-1][j+1]);
                }
                matrix[i][j] += minAbove;
            }
        }
        
        int minSum = INT_MAX;
        for (int j = 0; j < m; ++j) {
            minSum =min(minSum, matrix[n-1][j]);
        }
        
        return minSum;
    }
};