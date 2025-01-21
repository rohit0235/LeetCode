class Solution {
public:
    void moveZeroes(vector<int>& nums) {
            int n=nums.size();
            int nonze=0;
            for (int i=0;i<n;i++){
                if (nums[i]!=0){
                    swap(nums[i],nums[nonze]);
                    nonze++;
                }
            }
        
        // int i=0;
        // int j=0;
        //  int n=nums.size();
        // while (i<n && j<n){

     
        //     while (i<n && nums[i]!=0){
        //         i++;
        //     }
        //                 if (i==n) break;
        //                 j=i+1;
        //      while (j<n && nums[j]==0){
        //         j++;
        //     }
                
        //     if (j==n) break;
 
 
             
        //        if (i<j && nums[i]==0 && nums[j]!=0 ) swap(nums[i],nums[j]);
        //        else break;
        // }

    }
};