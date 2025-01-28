class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    bool valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& x,
            int& y, int& m, int& n) {

          visited[x][y] = true; // Mark the current cell as visited
        int count = grid[x][y]; // Include the current cell's fish count

        for (int i = 0; i < 4; i++) {
            int newx = x + dir[i];
            int newy = y + dir[i + 1];
        if (valid(newx,newy,m, n) && !visited[newx][newy] &&
               grid[newx][newy] > 0) {
                count += dfs(grid, visited, newx, newy, m, n);
            }
        }

        return count;
    }
    int findMaxFish(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int mini =0 ;
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (!visited[i][j] && grid[i][j] > 0) {

                    mini = max(mini, dfs(grid, visited, i, j, m, n));
                }
            }
        }

        return mini;
    }
};