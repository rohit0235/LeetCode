#include <vector>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                           vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m, vector<int>(n, -1));

        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 0;
        }

        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }

        for (int i = 0; i < m; ++i) {
            bool guarded = false;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) guarded = false;
                else if (grid[i][j] == 2) guarded = true;
                else if (guarded && grid[i][j] == -1) grid[i][j] = 1;
            }

            guarded = false;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) guarded = false;
                else if (grid[i][j] == 2) guarded = true;
                else if (guarded && grid[i][j] == -1) grid[i][j] = 1;
            }
        }

        for (int j = 0; j < n; ++j) {
            bool guarded = false;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 0) guarded = false;
                else if (grid[i][j] == 2) guarded = true;
                else if (guarded && grid[i][j] == -1) grid[i][j] = 1;
            }

            guarded = false;
            for (int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == 0) guarded = false;
                else if (grid[i][j] == 2) guarded = true;
                else if (guarded && grid[i][j] == -1) grid[i][j] = 1;
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) {
                    count++;
                }
            }
        }

        return count;
    }
};