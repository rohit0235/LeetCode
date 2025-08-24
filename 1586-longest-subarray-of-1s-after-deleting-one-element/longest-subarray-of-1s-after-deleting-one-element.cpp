class Solution {
public:
    int longestSubarray(vector<int>& nums) {

                    int n = nums.size();

                    int z= 0; 
                    int low = 0;
                    int curr =0;
                    int maxi =0;

                    for(int i=0;i<n;i++){ 
                              if (nums[i]==0) z++;
                              while (z>1){
                                    if (nums[low]==0) {
                                         z--;
                                    }
                                    low++;
                              }

                              maxi = max(maxi , i-low+1);
                              
                             
                    }  

                    return maxi-1 ;
  
         
    }
};