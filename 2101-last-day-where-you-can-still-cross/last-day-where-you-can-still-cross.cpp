class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {-1, 0, 1, 0};
    bool pos(int row, int col, vector<vector<int>>& grid, int idx) {

        queue<pair<int, int>> q;
        // cout<<idx<<" "<<endl;
        for (int i = 0; i < col; i++) {
            // cout<<grid[0][i]<<" ";
            if (grid[0][i] > idx || grid[0][i] == 0)
                q.push({0, i});
        }

        // while (!q.empty()) {
        //      cout<<q.front().first<<" "<<q.front().second<<" ";
        //                cout<<endl;
        //     q.pop();
        // }
        //   cout<<endl;

        vector<vector<int>> vis(row, vector<int>(col, false));

        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            int r = top.first;
            int c = top.second;
            if (r == row - 1)
                return true;
            for (int i = 0; i < 4; i++) {

                int newx = r + dx[i];
                int newy = c + dy[i];
                if (newx < 0 || newx >= row || newy < 0 || newy >= col ||
                    (grid[newx][newy] != 0 && grid[newx][newy] <= idx))
                    continue;
                if (vis[newx][newy])
                    continue;

                vis[newx][newy] = 1;
                q.push({newx, newy});
            }
        }

        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        //  int n = cells.size();
        //  int m= cells[0].size();
        int ans = 0;
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i < cells.size(); i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = i + 1;
        }

        // for (int i = 0; i < row; i++) {
        //     for (int j = 0; j < col; j++) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        int l = 0;
        int r = cells.size() - 1;
        int count = 0;
        while (l <= r) {
            // if (count == 3)
            //     break;
            // count++;
            // cout<<l<<" "<<r<<endl;
            int mid = (l + r) / 2;
            // cout<<mid<<endl;
            // int r = cells[mid][0] - 1;
            // int c = cells[mid][1] - 1;
            //  grid[r][c]=mid+;
            if (pos(row, col, grid, mid)) {

                ans = mid ;
                l = mid + 1;

            } else {
                // cout<<"Ye false hai "<<endl;
                r = mid - 1;
            }
        }

        return ans;
    }
};