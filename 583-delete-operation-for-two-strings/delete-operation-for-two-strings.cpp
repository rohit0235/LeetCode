class Solution {
public:
    int n ,m;
    int dp[501][501];
    int solve(string &w1, string& w2, int i, int j){

            if (i == n) return m - j;
    
        if (j == m) return n - i;
        if (dp[i][j]!=-1) return dp[i][j];
          
          if (w1[i]==w2[j]){
             return solve(w1, w2 , i+1 ,j+1);
          }
          int sec = 1+solve(w1, w2 , i+1 ,j);
          int thir = 1+solve(w1, w2 , i ,j+1);

          return dp[i][j]=min(sec, thir);

    }
   
    int minDistance(string w1, string w2) {
        n= w1.size();
        m= w2.size();
        memset(dp , -1, sizeof(dp));
        return solve(w1, w2, 0,0 );
    }
};