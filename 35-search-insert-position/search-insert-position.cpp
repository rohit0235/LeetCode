class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
                int lower= lower_bound(nums.begin(),nums.end(),target)-nums.begin();
                if (lower>=nums.size()){
                     return lower;
                }

                return lower;






                

    }
};