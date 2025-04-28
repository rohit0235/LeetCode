class Solution {
public:
      
    int n;

  int solve(vector<int>&prices,int i,int buy,int cap, vector<vector<vector<int>>>&dp){
              if (cap==0) return 0;
              if (i>=n) return 0;
               if (dp[i][buy][cap]!=-1) return dp[i][buy][cap];
              int op1=0,op2=0;
    

              if (buy){
                  
                      op1=-prices[i]+solve(prices,i+1,0,cap,dp);
                      op2=solve(prices,i+1,1,cap,dp);
              }

              else{
                   
                   op1=prices[i]+solve(prices,i+1,1,cap-1,dp);
                   op2=solve(prices,i+1,0,cap,dp);
              }

              return dp[i][buy][cap]=max(op1,op2);



    }

    int maxProfit(int k, vector<int>& prices) {
           n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k,dp);    
    }
};