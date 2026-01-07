class Solution {
public:
    int memo[10001];

    int solve(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return 1e9;
        if (memo[amount] != -1) return memo[amount];

        int minCoins = 1e9;
        for (int coin : coins) {
            int res = solve(coins, amount - coin);
            if (res != 1e9) {
                minCoins = min(minCoins, 1 + res);
            }
        }

        return memo[amount] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof(memo));
        int result = solve(coins, amount);
        return (result >= 1e9) ? -1 : result;
    }
};