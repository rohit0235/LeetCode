class Solution {
public:
    int n;
    vector<vector<int>> res;
    // unordered_set<int> st;
    // void solve(vector<int>& nums, vector<int>& s) {

    //     if (s.size() == n) {
    //         res.push_back(s);
    //         return;
    //     }

    //     for (int i = 0; i < n; i++) {
    //         if (st.find(nums[i]) == st.end()) {

    //             st.insert(nums[i]);
    //             s.push_back(nums[i]);
    //             solve(nums, s);
    //             s.pop_back();
    //             st.erase(nums[i]);
    //         }
    //     }
    // }

    // swapping approach

    void solve(vector<int>& nums, int idx) {

        if (idx == n) {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < n; i++) {

            swap(nums[i], nums[idx]);
            solve(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        n = nums.size();

        // vector<int> s;
        // solve(nums,s);
        solve(nums, 0);

        return res;
    }
};