class Solution {
public:
    int solve(int i,int j,int m,int n,  vector<vector<int>>&dp){
           
           if (i==m || j==n ){
             return 0;
           }
           
           if (i==m-1 && j==n-1) return 1;
           if (dp[i][j]!=-1) return dp[i][j]; 
           dp[i+1][j]=solve(i+1,j,m,n,dp);
           dp[i][j+1]=solve(i,j+1,m,n,dp);
           
            return dp[i][j]=dp[i+1][j]+dp[i][j+1];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(101,vector<int>(101,-1));
        return solve(0,0,m,n,dp);

    }
};