class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        

        int maxsum=0;
        int currentsum=0;
        int n=nums.size();
        if (n==1) return nums[0];
        for (int i=0;i<n-1;i++){
               
               currentsum+=nums[i];
               if (nums[i]>=nums[i+1]){
                          maxsum=max(currentsum,maxsum);
                          currentsum=0;
               }
        }
        if (nums[n-1]>nums[n-2]){
            currentsum+=nums[n-1];
        }
         maxsum=max(currentsum,maxsum);
        return maxsum;
    }
};