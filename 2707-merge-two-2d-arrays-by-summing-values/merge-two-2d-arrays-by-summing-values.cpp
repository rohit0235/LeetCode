class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
          vector<vector<int>>ans;

          int i=0;
          int j=0;
          int m=nums1.size();
          int n=nums2.size();
          
          while (i<m && j<n){
                if (nums1[i][0]==nums2[j][0]){
                     ans.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
                     i++;
                     j++;
                }
                else if (nums1[i][0]<nums2[j][0]){
                     ans.push_back({nums1[i][0],nums1[i][1]});
                     i++;
                }
                else{
                     ans.push_back({nums2[j][0],nums2[j][1]});
                     j++;
                }
          }
          
          while (i<m){
                       ans.push_back({nums1[i][0],nums1[i][1]});
                     i++;
          }
          
          while (j<n){
                     ans.push_back({nums2[j][0],nums2[j][1]});
                     j++;
          }

          return ans;
          

        //  unordered_map<int,int>mp;
        //  for(auto i:nums2) mp[i[0]]=i[1];
        //  for(auto i:mp) {
        //     cout<<i.first<<" "<<i.second<<endl;
        //  }
        //   int n=nums1.size();
        //  for(int i=0;i<n;i++){
             
        //        if (mp.find(nums1[i][0])!=mp.end()){
        //             nums1[i][1]+=mp[nums1[i][0]];
        //             mp.erase(nums1[i][0]);
        //        }
            
        //  }
        //  for(auto i:mp){
        //        nums1.push_back({i.first,i.second});
        //  } 
         
        //   sort(nums1.begin(),nums1.end());
        //   return nums1;


    }
};