class Solution {
public:
    int n;
    
     int dp[101][101];
    int solve(vector<int>&nums, int i, int prev){
             
             if(i>=n) return 0;
             int first =INT_MAX-1;
             int second =INT_MAX;
             if(dp[i][prev]!=-1) return dp[i][prev];
             if(prev!=0  && nums[i]<nums[prev-1]){
                   //matlab delete karna hi padega 
                    first = 1+solve(nums, i+1,prev);
             }
             else{
                    first = 1+solve(nums, i+1,prev);
                    second = solve(nums, i+1,i+1);
             }
            //  cout<<first<<" "<<second<<endl;
             
             return dp[i][prev]=min(first ,second);
    }
    int minimumOperations(vector<int>& nums) {
         n= nums.size();
   memset(dp,-1,sizeof(dp));
         return solve(nums , 0,0);
    }
};