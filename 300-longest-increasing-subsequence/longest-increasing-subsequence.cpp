class Solution {
public:
     int n;
     int solve(vector<int>& nums,int i,int j, vector<vector<int>>&dp){
            
            if (i>=n || j>=n) return 0;
            int take=0;
            if (dp[i+1][j]!=-1) return dp[i+1][j];
            if (i==-1 || nums[i]<nums[j]){
                take= 1+solve(nums,j,j+1,dp);
            }
            
          
            int skip =solve(nums,i,j+1,dp);
      

            return dp[i+1][j]=max(skip,take);
     }
    
    int lengthOfLIS(vector<int>& nums) {
            n=nums.size();
            vector<vector<int>>dp(n+1,vector<int>(n,-1));
            return solve(nums,-1,0,dp);
    }
};