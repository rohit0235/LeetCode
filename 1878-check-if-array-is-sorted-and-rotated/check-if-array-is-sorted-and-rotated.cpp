class Solution {
public:
     bool issorted(vector<int>& nums){
               for (int i=0;i<nums.size()-1;i++){
                    if (nums[i]>nums[i+1]){
                          return false;
                    }
               }
               return true;
     }
    bool check(vector<int>& nums) {
                        int n =nums.size();
                  int count=0;
                  if (issorted(nums)) return true;
                  for (int i=0;i<n-1;i++){
                        if (nums[i]>nums[i+1]){
                            count=i;
                            break;
                        }
                  }
                     reverse(nums.begin(),nums.begin()+count+1);
                reverse(nums.begin()+count+1,nums.end());
           
                reverse(nums.begin(),nums.end());   
                if (issorted(nums)) return true;
                else return false;
                  
      
 

    }
};