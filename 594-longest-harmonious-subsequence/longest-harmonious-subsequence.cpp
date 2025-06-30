class Solution {
public:
    int findLHS(vector<int>& nums) {
             // 1 2 2 2 3 3 5 7
             // 2 2 2 3 3
             // 1 2 3 4
           
                 int res=0;
                    // vector<int>s=nums;
                 sort(nums.begin(),nums.end());
                  unordered_map<int,int>mp;
                 for(int i=0;i<nums.size();i++) mp[nums[i]]=i;
                    int ans =0;
                for(int i=0;i<nums.size();i++){
                          
                           if (mp.find(nums[i]+1)!=mp.end()) { 
                               ans =max(ans,  abs(mp[nums[i]+1]-i+1));
                           }

                      
                }

                return ans;

    }
};