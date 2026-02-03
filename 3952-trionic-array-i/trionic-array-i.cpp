class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
     
        int decreasing = 0;
        int increasing = 0;
        if(nums[0]<nums[1]) increasing++;
        bool dec= false;
        for(int i=1;i<n;i++){
              if(nums[i]==nums[i-1]) return false;
              // increasing
              if(nums[i]>nums[i-1]){
                 if(dec){
                      increasing++;
                      dec= false;
                 }               
              }
              // decreasing
              if(nums[i]<nums[i-1]){
                 if(!dec){
                      decreasing++;
                      dec = true;
                 }               
              }
        }
           cout<<increasing<<" "<<decreasing;
        return decreasing==1 && increasing==2;
    }
};