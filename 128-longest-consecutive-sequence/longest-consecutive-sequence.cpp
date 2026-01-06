class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<int, int> valToIndex;
        for (int i = 0; i < n; i++) {
            if (valToIndex.count(nums[i])) continue;

            if (valToIndex.count(nums[i] - 1)) {
                unite(i, valToIndex[nums[i] - 1]);
            }
            if (valToIndex.count(nums[i] + 1)) {
                unite(i, valToIndex[nums[i] + 1]);
            }
            valToIndex[nums[i]] = i;
        }

        unordered_map<int, int> counts;
        int maxi = 0;
        for (auto const& [val, index] : valToIndex) {
            int root = find(index);
            counts[root]++;
            maxi = max(maxi, counts[root]);
        }

        return maxi;
    }
};