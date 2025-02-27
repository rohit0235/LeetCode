class Solution {
public:
    int solve(int first, int second, vector<int>& arr, unordered_map<int, int>& mp) {
        int target = arr[second] - arr[first];
        
        if (mp.find(target) != mp.end() && mp[target] < first) {
            return solve(mp[target], first, arr, mp) + 1;
        }
        return 2; // At least two elements form a sequence
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        int maxans = 0;
        for (int j = 1; j < n; j++) {  // Start `j` from 1 to ensure valid pairs
            for (int i = 0; i < j; i++) {  // Ensure `i < j`
                int result = solve(i, j, arr, mp);
                if (result > 2) {
                    maxans = max(result, maxans);
                }
            }
        }

        return maxans > 2 ? maxans : 0;
    }
};
