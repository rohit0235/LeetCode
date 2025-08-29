class Solution {
public:

   int solve(vector<int>&nums, int i, int prev,  vector<vector<int>>&dp){
     
         if (i>=nums.size()) return 0;
         if (prev!=-1 && dp[i][prev+1]!=-1) return dp[i][prev+1];
         int first =0;
         
         if (prev==-1 || nums[i]>nums[prev]){
            first =1+ solve(nums, i+1 , i,dp );
         }

         int second = solve(nums, i+1 , prev,dp);

         return dp[i][prev+1]=max(first ,second );
   }
   
    int lengthOfLIS(vector<int>& nums) {
             

              int n = nums.size();
            //   int maxi = *max_element(nums.begin(),nums.end());
            //   int mini = *min_element(nums.begin(),nums.end());
              vector<vector<int>>dp(2501, vector<int>(2501 , -1));
              return solve(nums, 0,-1,dp);
    }
};