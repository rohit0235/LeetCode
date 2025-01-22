class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
              vector<vector<int>>result;
            unordered_map<int,int>mp;
            unordered_map<int,int>mp2;
            vector<int>first;
            for (int i:nums1) mp[i]++; 
            for (int j:nums2) mp2[j]++;
            vector<int>second;
            
            for (auto i:mp){
                 if (mp2.find(i.first)==mp2.end()){
                            first.push_back(i.first);
                 }
            }
            
            for (auto i:mp2){
                 if (mp.find(i.first)==mp.end()){
                           second.push_back(i.first);
                 }
            }

          
            result.push_back(first);
                 result.push_back(second);
            return result;
            
    }
};