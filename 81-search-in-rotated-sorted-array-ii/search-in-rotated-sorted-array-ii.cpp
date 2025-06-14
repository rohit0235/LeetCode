class Solution {
public:
    bool search(vector<int>& nums, int target) {
          
            int n =nums.size();

            for(int i:nums){
                   if (i==target) return true;
            }

            return false;
    }
};