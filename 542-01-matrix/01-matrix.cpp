class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // sabhi 0 se bfs lagana hai
        // tabhi kam banega instead of  a will do for other node

        queue<pair<int, int>> q;
        vector<vector<int>> result(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

         multimap<int, int> mp = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {

            pair<int,int> front = q.front();
                    q.pop();
            int i = front.first;
            int j = front.second;

            for (auto dir : mp) {

                int newi = i + dir.first;
                int newj = j + dir.second;

                if (newi < n && newi >= 0 && newj < m && newj >= 0 &&
                    result[newi][newj] == -1) {

                         result[newi][newj]=1+result[i][j];
                         q.push({newi,newj});

                }
            }
        }

        return result;
    }
};