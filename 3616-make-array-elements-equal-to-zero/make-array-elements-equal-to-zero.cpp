class Solution {
public:
    int countValidSelections(vector<int>& nums) {
            
             int n = nums.size();
             vector<int>right(n,0);
             if (n==1 && nums[0]==0) return 2;
             right[n-1]=nums[n-1];
             for(int i =n-2;i>=0;i--){
                   right[i]=right[i+1]+nums[i];
             }
               int ans =0;
               int curr =0;
             for(int i=0;i<n;i++){
                    if (nums[i]==0){
                         if (curr==right[i]){
                             ans+=2;
                         }
                         if (abs(curr-right[i])==1){
                             ans+=1;
                         }
                         
                    }
                    curr+=nums[i];
             }

             return ans;
    }
};