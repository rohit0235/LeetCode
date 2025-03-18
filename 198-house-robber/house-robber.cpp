class Solution {
public:
    int n;
    
    // int solve(vector<int>&nums,int index,vector<int>&dp){

    //   if (index>=n) return 0;
    //   if (dp[index]!=-1) return dp[index];
    //  int  chori=nums[index]+solve(nums,index+2,dp);
    //  int  chorinahi=solve(nums,index+1,dp);
    //  return dp[index]=max(chori,chorinahi);

    // } 

    int rob(vector<int>& nums) {
        n=nums.size();
        vector<int>dp(n+1,0);
           dp[1] = nums[0];
        
        for(int i=2;i<=n;i++){ 
               
               dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
        }

        return dp[n];
        // return solve(nums,0,dp);
    }
};