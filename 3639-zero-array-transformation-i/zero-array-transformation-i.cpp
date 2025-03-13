class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
           int n=nums.size();
           vector<int>diff(n,0);
           for(int i=0;i<queries.size();i++){
             
                 int l=queries[i][0];
                 int r=queries[i][1];
                 diff[l]+=1;
                 if (r+1<n)
                 diff[r+1]-=1;
           }
           int curr=0;
           for(int i=0;i<n;i++){
                curr+=diff[i];
                if (nums[i]-curr>0) return false;
           }
           return true;
    }
};