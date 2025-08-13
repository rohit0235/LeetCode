class Solution {
public:
    int n;
    int dp[301][11];
    int solve(vector<int>& jd, int idx, int d) {
          if (dp[idx][d]!=-1) return dp[idx][d] ;
        if (d == 1) {
            int maxd = jd[idx];

            for (int i = idx; i < n; i++) {
                maxd = max(maxd, jd[i]);
            }

            return maxd;
        }
         
         int maxd = jd[idx];
         int result = INT_MAX;
        for (int i = idx; i <= n-d; i++) {
                   
                maxd =max( maxd, jd[i]);

                int f = maxd + solve(jd, i+1,d-1);
                result = min(result , f);
        }

        return dp[idx][d] = result;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
          memset(dp,-1,sizeof(dp));
        n = jobDifficulty.size();
          if (n<d) return -1;
        return solve(jobDifficulty, 0, d);
    }
};