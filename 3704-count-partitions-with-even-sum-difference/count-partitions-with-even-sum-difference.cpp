class Solution {
public:
    int countPartitions(vector<int>& nums) {
        // 
        int total = accumulate(nums.begin(),nums.end(),0);
        int left =0;
        int ans =0;
        for(int i:nums){
     
             left+=i;       if (left==total) break;
             int diff = total - 2*left ;
             if (abs(diff)%2==0) ans++;
        }
        return ans;
    }
};