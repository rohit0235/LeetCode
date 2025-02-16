class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
                 
                 unordered_map<int,int>mp;
                 int n=nums.size();
                 mp[nums[0]]=0;
                 for (int i=1;i<n;i++){
                         
                         if (mp.find(nums[i])!=mp.end()){
                               
                               int index=mp[nums[i]];
                               if (abs(index-i)<=k){
                                     return true;
                               }
                                   
                         }

                         mp[nums[i]]=i;
                          
                         
                 }

                 return false;


    }
};