class Solution {
public:
    
    int n;
    int t[5001][2];
    int solve(int i,vector<int>&prices,int buy){
             
          if (i >= n) return 0;

          if (t[i][buy]!=-1) return t[i][buy];
        int op1 = 0, op2 = 0;
        if (buy) {
            // Option 1: Buy the stock
            op1 = -prices[i] + solve(i + 1, prices, 0);
            // Option 2: Skip
            op2 = solve(i + 1, prices, 1);
        } else {
            // Option 1: Sell the stock
            op1 = prices[i] + solve(i + 2, prices, 1); // Cooldown 1 day after selling
            // Option 2: Skip
            op2 = solve(i + 1, prices, 0);
        }
        return t[i][buy]=max(op1, op2);

    }

    
    int maxProfit(vector<int>& prices) {
          n=prices.size();
          memset(t,-1,sizeof(t));
          return solve(0,prices,1);

    }
};