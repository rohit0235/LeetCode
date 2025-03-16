class Solution {
public:

    int solve(int n,int i,   vector<int>&dp){
           if (i==n) return 1;
           if (i>n) return 0;
           if (dp[i]!=-1) return dp[i];
           int first=solve(n,i+1,dp);
           int second=solve(n,i+2,dp);
           return dp[i]=first+second;

    }
    int climbStairs(int n) {
         vector<int>dp(n,-1);
         return solve(n,0,dp);
    }
};