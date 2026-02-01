class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int total = nums[0];
        
        sort(nums.begin()+1,nums.end());

        return total+nums[1]+nums[2];
         
    }
};