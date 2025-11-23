int dp[40000][3];

class Solution {
public:
    // static int f(int i, int mod, vector<int>& nums){
    //     if (i<0) return mod==0? 0:-1e9; 
    //     if (dp[i][mod]!=-1) return dp[i][mod];

    //     const int x=nums[i];
    //     int modPrev=mod-x%3; modPrev+=(-(modPrev<0)) & 3;

    //     int take=x+f(i-1, modPrev, nums);
    //     int skip=f(i-1, mod, nums);

    //     return dp[i][mod]=max(take, skip);
    // }

    static int maxSumDivThree(vector<int>& nums) {
        const int n=nums.size();
        // memset(dp, -1, sizeof(int)*n*3);
        // return max(0, f(n-1, 0, nums)); 
         sort(nums.begin(),nums.end());
         int sum = accumulate(nums.begin(),nums.end(),0);
         vector<int>one;
         vector<int>two;

         if (sum%3==0) return sum;
        
         for(int i:nums){
              if (i%3==0) continue;
              if (i%3==1){
                    if (one.size()<2) one.push_back(i);
              }
              if (i%3==2){
                    if (two.size()<2) two.push_back(i);
              }
         }
         
         if (sum%3==1){
               
               int mini = INT_MAX;
               if (one.size()>=1){
                    mini = min(mini, one[0]);
               }
               if (two.size()==2){
                   int f = two[0]+two[1];
                    mini = min(mini, f);
               }

              if (mini==INT_MAX){ 
                  return 0;
              } 
              else{
                 return sum-mini;
              }

         }
         if (sum%3==2){
               
               int mini = INT_MAX;
               if (two.size()>=1){
                    mini = min(mini, two[0]);
               }
               if (one.size()==2){
                   int f = one[0]+one[1];
                    mini = min(mini, f);
               }

              if (mini==INT_MAX){ 
                  return 0;
              } 
              else{
                 return sum-mini;
              }

         }
               return 0;

    }
};