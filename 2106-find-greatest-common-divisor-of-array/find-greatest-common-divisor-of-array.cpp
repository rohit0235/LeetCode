class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int n=nums.size();
        
    int mini = *min_element(nums.begin(),nums.end());
    int maxi = *max_element(nums.begin(),nums.end());

        return gcd(mini,maxi);
    }
};