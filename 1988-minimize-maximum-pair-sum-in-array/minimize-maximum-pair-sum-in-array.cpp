class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        // 2 3  3 5
        // 2 3 4 4 5 6
        sort(nums.begin(),nums.end());

        int ans =0;

        int l=0;
        int r =n-1;
        while (l<r){
               ans = max(ans , nums[l]+nums[r]);
               l++;
               r--;
        }
        return ans;
    }
};