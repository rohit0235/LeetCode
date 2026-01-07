class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
          int maxi =0;
          int buy = prices[0];

          for(int i:prices){
             buy = min(buy , i);
               maxi = max(maxi ,i-buy);   
          }
          return maxi;
    }
};