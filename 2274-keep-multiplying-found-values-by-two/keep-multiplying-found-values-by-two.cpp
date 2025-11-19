class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
          
           unordered_map<int,int>mp;
           for(auto i:nums){
               mp[i]++;
           }
           while (mp.count(original)){
            //   original*=2;
              mp[original]--;
              if (mp[original]==0){
                 mp.erase(original);
              }
              
                original*=2;
           }
           return original;
          
    }
};