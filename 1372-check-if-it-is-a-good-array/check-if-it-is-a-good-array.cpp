class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
           
           int n =nums.size();

           int g=nums[0]; 

           for(int i=1;i<n;i++){
                    g=gcd(g,nums[i]);
                    // for(int j=i+1;j<n;j++){
                    //      if (gcd(nums[i],nums[j])==1) return true;
                    // }
           }
         
            if (g==1) return true;
           return false;


    }
};