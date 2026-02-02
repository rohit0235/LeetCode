class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {

        int n = nums.size();
        long long ans = LLONG_MAX;

        priority_queue<int> small; 
        priority_queue<int, vector<int>, greater<int>> large;

        unordered_map<int,int> ds, dl;

        long long sum = 0;
        int smallSize = 0;

        auto cleanSmall = [&]() {
            while (!small.empty() && ds[small.top()]) {
                ds[small.top()]--;
                small.pop();
            }
        };

        auto cleanLarge = [&]() {
            while (!large.empty() && dl[large.top()]) {
                dl[large.top()]--;
                large.pop();
            }
        };

        auto moveSmallToLarge = [&]() {
            cleanSmall();
            int x = small.top(); small.pop();
            sum -= x;
            smallSize--;
            large.push(x);
        };

        auto moveLargeToSmall = [&]() {
            cleanLarge();
            int x = large.top(); large.pop();
            sum += x;
            small.push(x);
            smallSize++;
        };

        auto rebalance = [&]() {
            cleanSmall();
            cleanLarge();
            while (smallSize > k - 1) moveSmallToLarge();
            while (smallSize < k - 1) moveLargeToSmall();
        };

        for (int i = 1; i <= dist + 1; i++) {
            small.push(nums[i]);
            sum += nums[i];
            smallSize++;
        }

        rebalance();
        ans = nums[0] + sum;

        for (int i = dist + 2; i < n; i++) {

            int out = nums[i - dist - 1];

            if (!small.empty() && out <= small.top()) {
                ds[out]++;
                sum -= out;
                smallSize--;
            } else {
                dl[out]++;
            }

            int in = nums[i];

            cleanSmall();
            if (smallSize && in <= small.top()) {
                small.push(in);
                sum += in;
                smallSize++;
            } else {
                large.push(in);
            }

            rebalance();
            ans = min(ans, nums[0] + sum);
        }

        return ans;
    }
};
