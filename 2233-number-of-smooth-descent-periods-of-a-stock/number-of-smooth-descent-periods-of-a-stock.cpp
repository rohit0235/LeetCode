class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        if (n==1) return 1;

            long long ans =0;
           long long count =1;
        for(   long long i=1;i<n;i++){
              if (prices[i-1]-prices[i]!=1){
                  ans = ans + (count*(count+1))/2;
                  count =0;
              }
           count++;
        }     ans = ans + (count*(count+1))/2;
        return ans;
    }
};