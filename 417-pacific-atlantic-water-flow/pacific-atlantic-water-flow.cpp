class Solution {
public:
    int n, m;
    // pacific
    //     bool ispos1(vector<vector<int>>& heights, int i, int j, int
    //     prev,vector<vector<bool>>&vis1) {

    //         if (i >= n || i < 0 || j >= m || j < 0 || prev < heights[i][j] ||
    //         vis1[i][j])
    //             return false;
    //                if (i == 0 || j == 0)
    //             return true;
    //         vis1[i][j]= true;
    //         bool f = ispos1(heights, i + 1, j, heights[i][j],vis1);
    //         bool s = ispos1(heights, i, j + 1, heights[i][j],vis1);
    //         bool t = ispos1(heights, i, j - 1, heights[i][j],vis1);
    //         bool fo = ispos1(heights, i - 1, j, heights[i][j],vis1);
    //        vis1[i][j]= false;
    //         return f || s || t || fo;
    //     }
    //     bool ispos2(vector<vector<int>>& heights, int i, int j, int
    //     pre,vector<vector<bool>>&vis2) {

    //         if (i >= n || i < 0 || j >= m || j < 0 || pre < heights[i][j] ||
    //         vis2[i][j])
    //             return false;
    //             if (i == n-1 || j == m-1)
    //             return true;
    //  vis2[i][j]= true;
    //         bool f = ispos2(heights, i + 1, j, heights[i][j],vis2);
    //         bool s = ispos2(heights, i, j + 1, heights[i][j],vis2);
    //         bool t = ispos2(heights, i, j - 1, heights[i][j],vis2);
    //         bool fo = ispos2(heights, i - 1, j, heights[i][j],vis2);
    //  vis2[i][j]= false;
    //         return f || s || t || fo;
    //     }

    void solve(vector<vector<int>>& heights, int i, int j,
               vector<vector<bool>>& seen, int h = 0) {

        if (i < 0 || i >= n || j < 0 || j >= m)
            return;
        if (seen[i][j] || heights[i][j] < h)
            return;
        seen[i][j]= true;

        solve(heights,i+1,j,seen, heights[i][j]);
        solve(heights,i,j+1,seen, heights[i][j]);
        solve(heights,i-1,j,seen, heights[i][j]);
        solve(heights,i,j-1,seen, heights[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> seenp(n, vector<bool>(m, 0));
        vector<vector<bool>> seena(n, vector<bool>(m, 0));
       for (int j = 0; j < m; j++) {
    // Top row (Pacific)
    solve(heights, 0, j, seenp);
    // Bottom row (Atlantic)
    solve(heights, n - 1, j, seena);
}

// 2. Iterate over rows for the left and right columns
for (int i = 0; i < n; i++) {
    // Left column (Pacific)
    solve(heights, i, 0, seenp);
    // Right column (Atlantic)
    solve(heights, i, m - 1, seena);
}
        
        for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                    if (seenp[i][j] && seena[i][j]) {
                         result.push_back({i,j});
                    }
               }
        }
        return result;
        //     for (int i = 0; i < n; i++) {

        //         for (int j = 0; j < m; j++) {
        //  vector<vector<bool>>vis1(n, vector<bool>(m,false));
        //     vector<vector<bool>>vis2(n, vector<bool>(m,false));
        //             if (ispos1(heights, i, j, INT_MAX,vis1) &&
        //             ispos2(heights, i, j, INT_MAX,vis2)) {

        //                 result.push_back({i, j});

        //             }
        //         }
        //     }
    }
};