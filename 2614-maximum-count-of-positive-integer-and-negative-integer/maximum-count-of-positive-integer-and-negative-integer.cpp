class Solution {
public:
    int maximumCount(vector<int>& nums) {
            int count=0;
            int n=nums.size();
            int z=0;
            for(int i:nums){
                     if (i==0) z++;
                     else if (i>0) break;
                     else  count++;
            }

            return max(count,n-count-z);
            
     }
};