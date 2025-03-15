class Solution {
public:
    int n;
    int result(vector<int>&nums,int i,vector<int>&dp){
             
             if (i>=n) return 0;
            if (dp[i]!=-1) return dp[i];
             int take=nums[i]+result(nums,i+2,dp);
             int nottake=result(nums,i+1,dp);
            //   cout<<take<<" "<<nottake<<" "<<endl;
             return dp[i]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
         vector<int>dp(n,-1);
        return result(nums,0,dp);
    }
};