class Solution {
public:
    // int solve(int i,int j,int m,int n,  vector<vector<int>>&dp){
           
    //        if (i==m || j==n ){
    //          return 0;
    //        }
           
    //        if (i==m-1 && j==n-1) return 1;
    //        if (dp[i][j]!=-1) return dp[i][j]; 
    //        dp[i+1][j]=solve(i+1,j,m,n,dp);
    //        dp[i][j+1]=solve(i,j+1,m,n,dp);
           
    //         return dp[i][j]=dp[i+1][j]+dp[i][j+1];
    // }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        // return solve(0,0,m,n,dp);
        
        // vector<int>dp(101,0);
       dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
              
              for(int j=n-1;j>=0;j--){
                    if (i+1<m) dp[i][j]+=dp[i+1][j];
                    if (j+1<n) dp[i][j]+=dp[i][j+1];

                    // dp[i][j]+=dp[i][j+1]+
              }
        }

        return dp[0][0];




    }
};