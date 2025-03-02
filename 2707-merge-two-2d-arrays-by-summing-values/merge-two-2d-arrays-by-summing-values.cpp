class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
         
         unordered_map<int,int>mp;
         for(auto i:nums2) mp[i[0]]=i[1];
         for(auto i:mp) {
            cout<<i.first<<" "<<i.second<<endl;
         }
          int n=nums1.size();
         for(int i=0;i<n;i++){
             
               if (mp.find(nums1[i][0])!=mp.end()){
                    nums1[i][1]+=mp[nums1[i][0]];
                    mp.erase(nums1[i][0]);
               }
            
         }
         for(auto i:mp){
               nums1.push_back({i.first,i.second});
         }
         
          sort(nums1.begin(),nums1.end());
          return nums1;


    }
};