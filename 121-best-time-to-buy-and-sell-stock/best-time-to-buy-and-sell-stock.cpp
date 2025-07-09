class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
            int maxprofit =0;
            int buy =prices[0];

            for(int i=1;i<prices.size();i++){
                     
                     maxprofit = max(maxprofit, prices[i]-buy);
                   if (buy>prices[i]) buy=prices[i];
            }

            return maxprofit;
    }
};