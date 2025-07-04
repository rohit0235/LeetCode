class Solution {
public:

      
        int dp[1001][1001];
      int solve(int copy , int clip , int n){
           
            if (copy==n) return 0;

            if (copy>n) return 1000000;

            if (dp[copy][clip]!=-1) return dp[copy][clip];

            int copyandpaste =1+1+ solve(copy+copy,copy , n);
            int paste= 1+solve(copy+clip ,clip , n);

            return dp[copy][clip]=min(copyandpaste,paste )   ;         
            
      }

    int minSteps(int n) {
        if (n==1) return 0;
        memset(dp,-1,sizeof(dp));

        return 1+solve(1,1,n);
    }
};