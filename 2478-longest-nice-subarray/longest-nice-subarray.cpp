class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
          
          int mask=0,left=0,maxlen=0;
           int n=nums.size();
          for(int right=0;right<n;right++){
                  
               while ((mask & nums[right])!=0){
                        mask^=nums[left];
                        left++;
                  }

                  mask|=nums[right];

                  maxlen=max(maxlen,right-left+1);
          }

          return maxlen;
    }
};