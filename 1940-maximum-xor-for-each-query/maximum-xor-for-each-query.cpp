class Solution {
public:
    int solve(int n, int r) {
        int x = 0;
        for (int i = 31 - __builtin_clz(r | 1); i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (bit == 0) {
                if ((x | (1 << i)) <= r) {
                    x |= (1 << i);
                }
            } else {
                if (x > r) {
                    // This branch logic is simplified
                    // for the range [0, R]
                }
            }
        }
        return x;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        long long maxi = pow(2, maximumBit) - 1;

        long long ans = 0;

        for (int i : nums)
            ans ^= i;
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {

            int k = solve(ans, maxi);
            // cout << k << " " << ans << endl;
            res[i] = k;

            ans ^= nums[i];
            // cout << ans << endl;
            // nums.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};