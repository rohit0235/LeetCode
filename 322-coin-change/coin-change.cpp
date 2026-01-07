class Solution {
public:
    int n  ;
    vector<vector<int>>dp;
     int solve(vector<int>& coins, int amount, int idx ){
          
           if (amount==0) return 0;
           if (amount<0) return INT_MAX;

           if(idx>=n) return INT_MAX;
           if(dp[idx][amount]!=-1) return  dp[idx][amount];
            int f =INT_MAX; 
            if(amount-coins[idx]>=0){
                     int check = solve(coins , amount - coins[idx], idx);
                     if(check!=INT_MAX){
                         f = 1+ check;
                     }
            }
        
           int s = solve(coins , amount , idx+1);
           return  dp[idx][amount]=min(f,s);

           
     }
    int coinChange(vector<int>& coins, int amount) {
           n = coins.size();
          dp.resize(n+1,vector<int>(amount+1,-1));
          int check = solve(coins , amount , 0);
         if (check==INT_MAX) return -1;
         return check;
    }
};