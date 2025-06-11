#include <vector>
#include <algorithm> // For std::min
#include <climits>   // For INT_MAX

class Solution {
public:
    int n;
    std::vector<std::vector<int>> dp;

    int solve(std::vector<int>& coins, int amount, int i, int total) {
        // Base Cases:
        if (total == amount) {
            return 0; // 0 more coins needed
        }
        
        // If we have run out of coins OR exceeded the target amount
        if (i >= n || total > amount) {
            return INT_MAX; // This path is invalid/impossible
        }
        
        // Memoization check
        if (dp[i][total] != -1) {
            return dp[i][total];
        }

        int count1 = INT_MAX; // Coins needed if we include coins[i]

        // Choice 1: Include the current coin (coins[i])
        // We need to carefully check for overflow before adding total + coins[i]
        // The condition `total + coins[i] <= amount` should be written as:
        // `coins[i] <= amount - total` to prevent overflow when `amount - total` is evaluated first.
        // Also, if `amount - total` becomes negative (meaning total already exceeds amount),
        // then `coins[i] <= amount - total` would not work.
        // A safer check is: if `coins[i] > amount - total` then it will definitely overflow or exceed amount.
        // So, `if (coins[i] <= amount - total)` is the correct approach here.
        if (coins[i] <= amount - total) { // This prevents overflow of total + coins[i]
                                          // And also ensures total + coins[i] will not exceed amount
            int result_if_included = solve(coins, amount, i, total + coins[i]);
            if (result_if_included != INT_MAX) {
                count1 = 1 + result_if_included;
            }
        }
        
        // Choice 2: Exclude the current coin (coins[i])
        // Move to the next coin (i+1) without using coins[i].
        int count2 = solve(coins, amount, i + 1, total);

        // Store and return the minimum of the two valid choices
        dp[i][total] = std::min(count1, count2);
        return dp[i][total];
    }

    int coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        
        n = coins.size();
        // Initialize dp table: rows for coin indices (0 to n-1), columns for accumulated total (0 to amount)
        dp.assign(n, std::vector<int>(amount + 1, -1));

        int result = solve(coins, amount, 0, 0);

        // If result is INT_MAX, it means the amount cannot be made.
        if (result == INT_MAX) {
            return -1;
        } else {
            return result;
        }
    }
};