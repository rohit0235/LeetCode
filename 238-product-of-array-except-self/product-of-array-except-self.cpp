class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
           
           int zer=0;
           int n =nums.size();
           long long prod=1;
           for (int i=0;i<n;i++){
                if (nums[i]==0) zer++;
                else prod*=nums[i];
           }
             
           for (int i=0;i<n;i++){
               
               if (zer>1) nums[i]=0;
                else if (nums[i]==0 && zer==1) nums[i]=prod;
                else if (zer==1) nums[i]=0;
                else nums[i]=prod/nums[i];
           }
            return nums;


    }
};