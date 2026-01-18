class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> rsum(n, vector<int>(m, 0));
        vector<vector<int>> csum(n, vector<int>(m, 0));

        // prefix sums
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rsum[i][j] = grid[i][j] + (j > 0 ? rsum[i][j - 1] : 0);
                csum[i][j] = grid[i][j] + (i > 0 ? csum[i - 1][j] : 0);
            }
        }

        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // size of square
                for (int k = 1; i + k < n && j + k < m; k++) {

                    int newr = i + k;
                    int newc = j + k;

                    int target = 0;
                    bool ok = true;

                    // diagonal sums
                    int ld = 0, rd = 0;
                    for (int d = 0; d <= k; d++) {
                        ld += grid[i + d][j + d];
                        rd += grid[i + d][j + k - d];
                    }

                    // check row sums
                    for (int r = i; r <= newr && ok; r++) {
                        int row = rsum[r][newc] - (j > 0 ? rsum[r][j - 1] : 0);
                        if (r == i) target = row;
                        else if (row != target) ok = false;
                    }

                    // check column sums
                    for (int c = j; c <= newc && ok; c++) {
                        int column = csum[newr][c] - (i > 0 ? csum[i - 1][c] : 0);
                        if (column != target) ok = false;
                    }

                    if (ok && ld == target && rd == target) {
                        maxi = max(maxi, k + 1);
                    }
                }
            }
        }

        return maxi;
    }
};
