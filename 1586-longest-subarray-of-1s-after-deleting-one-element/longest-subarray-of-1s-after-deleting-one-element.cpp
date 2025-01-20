class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
            int k=1;
            int i=0;
            int j=0;
           int len=0;
           int n =nums.size();
            int  maxlen=0;
            while (i<n){
           
             if (nums[i]==0){
                k--;
             }

             len++;
             i++;

             while (k<0){
                  
                  if (nums[j]==0) k++;
                  len--;
                  j++;
             }

             maxlen=max(maxlen,len);

            }

            return maxlen-1;

            
         }

};