class Solution {
public:
    vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> result;
    void solve(vector<int>& curr, int k, int target, int i) {
        if (target < 0)
            return;
        if (target == 0 && curr.size() == k) {
            result.push_back(curr);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {

            curr.push_back(candidates[j]);
            solve(curr, k, target-candidates[j], j + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        solve(curr, k, n, 0);

        return result;
    }
};