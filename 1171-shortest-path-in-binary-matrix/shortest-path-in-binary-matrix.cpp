class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
 if (grid[0][0]==1) return -1;
 if (n==1 && m==1 && grid[0][0]==0) return 1;
         vector<int> dx = {-1, 0, 1, 0, 1, -1, 1, -1};
        vector<int> dy = {0, -1, 0, 1, -1, 1, 1, -1};
        int s = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {

            int yy = q.size();
            s++;
            for (int i = 0; i < yy; i++) {
                pair<int, int> f = q.front();
                q.pop();
                    // grid[f.first][f.second] == -1;
                for (int i = 0; i < 8; i++){
                    int nx = f.first + dx[i];
                    int ny = f.second + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        grid[nx][ny] == 0) {
     if (nx == n - 1 && ny == m - 1 ) return s+1;
                        q.push({nx, ny});
                        grid[nx][ny] = -1;
                    }
                }
            }
        }
        return -1;
    }
};