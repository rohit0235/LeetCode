class Solution {
private:
    int n;
    int totalZ; // Renamed 'z' to 'totalZ' for better readability and to avoid name confusion
    // memo[i][current_sum] stores the minimum difference achievable 
    // from index i onwards, given the current subset sum is current_sum.
    vector<vector<int>> memo;

    int solve(const vector<int>& stones, int currentSum, int i) {
        // Base Case: All stones have been considered.
        if (i == n) {
            // S1 = currentSum, S2 = totalZ - currentSum
            // Difference is |S2 - S1| = |totalZ - currentSum - currentSum|
            return abs(totalZ - 2 * currentSum);
        }

        // Check Memoization Table
        if (memo[i][currentSum] != -1) {
            return memo[i][currentSum];
        }

        // Choice 1: Include stones[i] in the current subset (Pile S1)
        int include = solve(stones, currentSum + stones[i], i + 1);

        // Choice 2: Exclude stones[i] from the current subset (put in Pile S2)
        int exclude = solve(stones, currentSum, i + 1);
        
        // Store the result before returning
        return memo[i][currentSum] = min(include, exclude);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        // 1. Calculate Total Sum and fix the class variable n
        n = stones.size();
        totalZ = 0;
        for (int stone : stones) {
            totalZ += stone;
        }

        // 2. Initialize the memoization table
        // Max 'i' is n (up to 30)
        // Max 'currentSum' is totalZ (up to 3000)
        memo.assign(n, vector<int>(totalZ + 1, -1));

        // 3. Start the recursive call
        // total is not passed as it's no longer necessary for the fixed structure.
        return solve(stones, 0, 0);
    }
};