class Solution {
public:
    void nextPermutation(vector<int>& nums) {
          
        //  next_permutation(nums.begin(),nums.end());
             int n=nums.size();

           int gi=-1;
           for(int i=n-1;i>0;i--){
                    
                    if (nums[i]>nums[i-1]){
                         gi = i-1;
                         break;
                    }

           }
         
            if(gi!=-1) {
             int  swapindex=gi;
            
           for(int i=n-1;i>=gi+1;i--){
                    
                    if (nums[i]>nums[gi]){
                        swapindex=i;
                         break;
                    }

           

            }
                 swap(nums[gi],nums[swapindex]);
            }

            reverse(nums.begin()+gi+1,nums.end());

            

    }
};