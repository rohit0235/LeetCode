class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
              

                         int n = nums.size();

                int lowerbound = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
                 int uprbound = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
                  
                if (lowerbound>=n) return {-1,-1};
                if (nums[lowerbound]!=target) return {-1,-1};


                return {lowerbound , uprbound-1};
                   

    }
};
