class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                unordered_set<int> st;
                int ds1 = 0;
                int ds2 = 0;
                bool possible = true;
                vector<int> rowSums(3, 0);
                vector<int> colSums(3, 0);

                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        int val = grid[i + r][j + c];
                        
                        if (val < 1 || val > 9) {
                            possible = false;
                        }
                        
                        st.insert(val);
                        rowSums[r] += val;
                        colSums[c] += val;

                        if (r == c) ds1 += val;
                        if (r + c == 2) ds2 += val;
                    }
                }

                if (!possible || st.size() != 9) continue;

                bool all15 = (ds1 == 15 && ds2 == 15);
                for (int k = 0; k < 3; k++) {
                    if (rowSums[k] != 15 || colSums[k] != 15) {
                        all15 = false;
                        break;
                    }
                }

                if (all15) ans++;
            }
        }
        return ans;
    }
};