class Solution {
public:
    int jump(vector<int>& nums) {
         int n = nums.size();

         int curr =0;
         int fart=0;
         int ans =0;

         for(int i=0;i<n-1;i++){
                
                 fart = max(fart , i+nums[i]);
                 if(i==curr){
                     ans++;
                     curr = fart;
                 }
                
         }
         return ans;
    }
};