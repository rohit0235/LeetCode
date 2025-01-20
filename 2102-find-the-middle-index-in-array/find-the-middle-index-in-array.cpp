class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
          int total=accumulate(nums.begin(),nums.end(),0);
            int n =nums.size();
               int leftsum=0;
               
            for (int i=0;i<n;i++){
                 
                  leftsum+=nums[i];
        
                  if (leftsum-nums[i]==total-leftsum){
                    return i;
                  }
                  
            }
            return -1;
    }
};