class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
         int c =1;
         int n = nums.size();
        for(int i=1;i<n;i++){
            if (nums[i]!=nums[i-1]) c++;
            if(c==3) return nums[i];
        }

        return nums[0];
    }
};