class Solution {
private:
    bool isValid(vector<vector<int>>& grid, int X, int Y) {
        return X >= 0 && Y >= 0 && X < grid.size() && Y < grid[0].size();
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();

        vector<vector<int>> grid(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;
        int dir[2][4] = {{0, -1, 1, 0}, {1, 0, 0, -1}};

        // Initialize water cells
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isWater[i][j] == 1) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // BFS to fill heights
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newX = x + dir[0][i];
                int newY = y + dir[1][i];
                if (isValid(grid, newX, newY) && grid[newX][newY] == -1) {
                    grid[newX][newY] = grid[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return grid;
    }
};