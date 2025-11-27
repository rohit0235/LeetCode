class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
 int n = nums.size();
    std::vector<long long> prefixSum(n + 1, 0);
    
    // Calculate prefix sums
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    // Map to store the minimum prefix sum for each remainder
    std::unordered_map<int, long long> minPrefix;
    minPrefix[0] = 0; // Initialize with the base case

    long long maxSum = std::numeric_limits<long long>::min();

    // Iterate through prefix sums
    for (int i = 1; i <= n; ++i) {
        int remainder = i % k;

        // Check if we can form a valid subarray
        if (minPrefix.find(remainder) != minPrefix.end()) {
            maxSum = std::max(maxSum, prefixSum[i] - minPrefix[remainder]);
        }

        // Update the minimum prefix sum for this remainder
        if (minPrefix.find(remainder) == minPrefix.end() || 
            prefixSum[i] < minPrefix[remainder]) {
            minPrefix[remainder] = prefixSum[i];
        }
    }

    return maxSum;
    }
};