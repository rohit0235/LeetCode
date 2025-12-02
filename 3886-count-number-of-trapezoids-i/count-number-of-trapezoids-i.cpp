class Solution {
public:

      const int mod = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
          
           unordered_map<int,int>mp;
           for(auto p :points){
             long long y = p[1];
             mp[y]++;
           }
           long long prev =0;
           long long ans =0;
           for(auto i:mp){
               long long yc = i.second;
               long long count = ((yc)*(yc-1))/2;
               ans+=count*prev;
               prev+=count;
           }
           return ans%mod;
    }
};