class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {

        sort(h.rbegin(), h.rend());
           long long  ans = 0;
        for (   long long  i = 0; i < k; i++) {
               long long  j = h[i] - i;

            if (j < 0) {
                break;
            }
            ans += j;
        }
        return ans;
    }
};