class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int r = 0;
        int c = m - 1;
        int ans = 0;
        while (r < n ) {

            while (r < n && c >= 0 && grid[r][c] >= 0) {

                 ans+=(m-c-1);
                r++;
            }
            while (c >= 0 && r < n && grid[r][c] < 0) {
                c--;
            }
            if(r<n) ans += (m - c - 1);
            r++;
            cout << ans << endl;
        }

        return ans;
    }
};