class Solution {
public:
     int n,m;
     const int MOD =1e9+7;
     int count =0;
    int solve(vector<vector<int>>& grid , int i ,int j, int sum ,  vector<vector<vector<int>>>&dp, int k){
        if (i==n-1 && j==m-1){
                     int curr = (sum+ grid[i][j])%k;
                    if (curr%k==0) {
                        //  count++;
                         return 1;
                    }
                    else{
                         return 0;
                    }
          };
          if (i<0 || i>=n || j<0 || j>=m) return 0;
        //   if (sum>k) return 0;
          if(dp[i][j][sum]!=-1) return dp[i][j][sum];
          int next =( sum+grid[i][j])%k;
          int first = solve(grid, i+1,j,next,dp,k);
          int second = solve(grid, i,j+1, next,dp,k);

          return dp[i][j][sum] =( first+ second)%MOD;
           
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        n= grid.size();         
        m= grid[0].size();
       
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        
    return     solve(grid,0,0, 0,dp,k);
            // return count;

    }
};