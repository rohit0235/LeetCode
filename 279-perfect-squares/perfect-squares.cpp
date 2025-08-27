class Solution {
public:

    int solve(int n , int i, vector<int>&temp, vector<vector<int>>&dp){
             if (n==0) return 0;
             if (n<0) return 1e9;
             if (i>=temp.size()) return 1e9;
             if (dp[n][i]!=-1) return dp[n][i];
            //   int first=0 ;
            
            int first =1+ solve(n-temp[i],i,temp , dp);
             int second = solve(n,i+1,temp, dp);

                //  cout<<first<<" "<<second;
             return dp[n][i] = min(first , second);

           
    }
    int numSquares(int n) {
           
            vector<int>temp;
            for(int i=1;i*i<=n;i++){
                   temp.push_back(i*i);
            }
            
            vector<vector<int>>dp(n+1, vector<int>(temp.size(),-1));
            return solve(n,0,temp ,dp );
           
    }
};