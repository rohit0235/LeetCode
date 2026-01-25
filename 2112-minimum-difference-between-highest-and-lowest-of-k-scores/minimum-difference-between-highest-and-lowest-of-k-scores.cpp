class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
         int n = nums.size();
     
         sort(nums.begin(),nums.end());

         int mindiff = INT_MAX;

         for(int i=k-1;i<n;i++){
               mindiff = min(mindiff,nums[i]-nums[i-k+1]);
         }

         return mindiff;
        
    }
};