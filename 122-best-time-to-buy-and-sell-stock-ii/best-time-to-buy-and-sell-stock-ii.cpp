class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
          int n = prices.size();
          int buy = prices[0];
          int maxi = 0;

          for(int i=0;i<n;i++){
               if(prices[i]>buy){
                    maxi+=prices[i]-buy;
                    buy = prices[i];
               }
               buy = min(buy , prices[i]);
          }

          return maxi;
    }
};