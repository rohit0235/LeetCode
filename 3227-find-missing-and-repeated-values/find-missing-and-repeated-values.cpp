class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
                 int n=grid.size();
                 int total=0;
                 unordered_map<int,int>mp;
                 vector<int>ans(2,-1);
                 for(int i=0;i<n;i++){
                       for(int j=0;j<n;j++){
                                total+=grid[i][j];
                                 mp[grid[i][j]]++;
                               if(mp[grid[i][j]]==2){
                                ans[0]=grid[i][j];
                               }
                       }
                 }

                 int req= ((n*n)*(n*n+1))/2;
                 ans[1] =req-(total-ans[0]);
                 return ans;

                  



    }
};