class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        long long frs=accumulate(begin(grid[0]),end(grid[0]),0LL);

        long long srs=0;

        long long mini=LONG_LONG_MAX;

        for (int i=0;i<col;i++){

            frs-=grid[0][i];

            long long best= max(frs,srs);
            mini=min(mini,best);
            srs+=grid[1][i];

        }

        return mini;


    }
};