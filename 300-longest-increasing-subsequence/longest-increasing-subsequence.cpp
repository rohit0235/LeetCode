// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
        
//     }
// };

class Solution {
public:
    
     vector<vector<int>>dp;
    int solve(vector<int>&nums, int i, int prev){
         if(i>=nums.size()) return 0;
           if(dp[i][prev+1]!=-1) return dp[i][prev+1];
         int f =0;
         int s = 0;
         if(prev==-1 ||nums[i]>nums[prev]  ){
              f= 1+    solve(nums , i+1 , i);
              s =  solve(nums ,i+1 , prev);
         }
         else{
                       s =  solve(nums , i+1 , prev);
         }
         

        //   cout<<f<<" "<<s<<endl;
         return dp[i][prev+1]= max(f,s);

    }
 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(nums,  0, -1);
    }
};