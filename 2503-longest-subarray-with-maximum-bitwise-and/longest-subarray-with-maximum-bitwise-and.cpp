class Solution {
public:
    int longestSubarray(vector<int>& nums) {
             
              int n  = nums.size();
              
              int maxi = *max_element(nums.begin(),nums.end());
              int count =0;
              int maxa =0;
              for(int  i =0;i<nums.size();i++){
                        
                       if (nums[i] == maxi){
                         count++; 
                       }
                       else if (count>0){
                            
                              count=0;
                       }maxa = max(maxa , count);

                       


              }

              return   maxa;


    }
};