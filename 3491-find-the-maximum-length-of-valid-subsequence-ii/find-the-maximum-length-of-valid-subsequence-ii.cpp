class Solution {
public:
    // int solve(vector<int>& nums, int k, int i, int prev1, int prev2,vector<vector<vector<int>>>&dp) {

    //     if (i >= nums.size())
    //         return 0;
    //      if (dp[i][prev1+1][prev2+1]!=-1) return dp[i][prev1+1][prev2+1];
    //     int f = 0;
    //     int s = 0;
    //     // int th = 0;

    //     if (prev1 == -1 || prev2 == -1 ||
    //         ((nums[prev2] + nums[i]) % k) ==
    //             ((nums[prev2] + nums[prev1]) % k)) {

    //         f = 1+solve(nums, k, i + 1, prev2,i,dp);
    //     }

    //     s = solve(nums, k, i + 1, prev1, prev2,dp);

    //     return dp[i][prev1+1][prev2+1] =max(f,s);
    // }

    int maximumLength(vector<int>& nums, int k) {
         int n = nums.size();
         
        unordered_map<int,int>dp[n+1];
            int ans =0;
        for(int i=1;i<n;i++){
              
               for(int j=0;j<i;j++){
                   
                        int diff =( nums[i]+nums[j])%k;
                        int cnt =1;

                        if (dp[j].count(diff)){
                             cnt =dp[j][diff];
                        }

                        dp[i][diff] = 1+ cnt;

                        ans = max(ans , dp[i][diff]);



               }
               
        }

        return ans;



    }
};