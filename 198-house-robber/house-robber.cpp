class Solution {
public:
    int n;
    
    int solve(vector<int>&nums,int index,vector<int>&dp){

      if (index>=n) return 0;
      if (dp[index]!=-1) return dp[index];
     int  chori=nums[index]+solve(nums,index+2,dp);
     int  chorinahi=solve(nums,index+1,dp);
     return dp[index]=max(chori,chorinahi);

    } 

    int rob(vector<int>& nums) {
        n=nums.size();
        vector<int>dp(n+1,-1);

        return solve(nums,0,dp);
    }
};