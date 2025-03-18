class Solution {
public:
    int n;

    int  solve (vector<int>&cost,int index,  vector<int>&dp){
            
            if(index>=n) return 0;
             if (dp[index]!=-1) return dp[index];
    return dp[index]= cost[index]+min(solve(cost,index+1,dp),solve(cost,index+2,dp));
             
    }
    int minCostClimbingStairs(vector<int>& cost) {
           
           n =cost.size();
        
          vector<int>dp(n+1,-1);
           return min(solve(cost,0,dp),solve(cost,1,dp));
    }
};