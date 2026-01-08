class Solution {
public:
    int n,m;
    int dp[501][501][2];
    int solve(vector<int>&nums1, vector<int>&nums2, int i, int j, bool picked){
          
          if(i>=n || j>=m || i<0 || j<0) {
             return picked==0? -1e9:0;
          }
            if( dp[i][j][picked]!=-1) return  dp[i][j][picked];
          int fi = nums1[i]*nums2[j]+solve(nums1,nums2, i+1,j+1, true);
          int se = solve(nums1,nums2, i+1,j,picked);
          int th =solve(nums1,nums2, i,j+1,picked);
        //   cout<<fi<<" "<<se<<" "<<th<<endl;
          return dp[i][j][picked]=max(fi,max(se,th));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // 2 3 
        // 4 6
        memset(dp,-1,sizeof(dp));
        n= nums1.size();
        m= nums2.size();

        return solve(nums1,nums2, 0,0,false);
    }
};