class Solution {
public:

     set<vector<int>>res;
         int n;
     void solve(vector<int>&nums,  vector<int>&subset,int i){
             
              if (i>=n) {
              res.insert(subset);
             return ;
              }
              subset.push_back(nums[i]);
           
              solve(nums,subset ,i+1);
             subset.pop_back();
                     while (i + 1 < n && nums[i] == nums[i+1]) {
            i++; // Skip duplicate element
        }
             solve(nums,subset ,i+1);
            
     }
     

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
             n= nums.size();
            sort(nums.begin(), nums.end());
            vector<int>subset;
            // for (int i=0;i<n;i++)
            solve(nums,subset, 0);
         vector<vector<int>>final;
           for(auto i:res){
                 final.push_back(i);
           }
          


        return final;
    }
};