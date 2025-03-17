class Solution {
public:

   static bool comp(pair<int,int>&p1,pair<int,int>&p2){
            
            if (p1.second==p2.second){
                 return p1.first>p2.first;
            }
            return p1.second<p2.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
         
         map<int,int>mp;
         for(int i:nums){
             mp[i]++;
         }
          vector<pair<int, int>>freq(mp.begin(),mp.end());
          sort(freq.begin(),freq.end(),comp);
          vector<int>ans;
         for(auto i:freq){
             for(int j=0;j<i.second;j++){
                 ans.push_back(i.first);
             }
         }
             return ans;
         
    }
};