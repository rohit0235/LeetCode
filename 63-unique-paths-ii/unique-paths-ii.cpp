class Solution {
public:
   int n ,m;
    int dp[101][101];
   
    int pos(vector<vector<int>>&og , int i, int j){
         if (i==n-1 && j==m-1 &&  og[i][j]!=1) return 1;
         if (i>=n || j>=m  || og[i][j]==1) return 0;
         if (dp[i][j]!=-1) return dp[i][j];
        int t =  pos(og , i+1  ,j);
        int p =  pos(og , i ,j+1);
        // if (t){
        //      return 1+ t;
        // }
        // if (p){
        //      return 1+ p;
        // }
        return dp[i][j]= t+p;
        // return t+p;


    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
         n = og.size();
         m = og[0].size();
        memset(dp , -1 , sizeof(dp));
        return pos(og , 0,0);

    }
};