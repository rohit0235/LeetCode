class Solution {
public:
    int n;

    string solve(string combination, unordered_map<string, int> &mp) {
        if (combination.size() == n) {
            if (mp.find(combination) == mp.end()) {
                return combination;
            }
            return "";
        }

        for (int i = 0; i <= 1; i++) {
            combination += (i == 0 ? '0' : '1'); // Append binary digit

            string res = solve(combination, mp);
            if (!res.empty()) return res; // If found, return immediately

            combination.pop_back(); // Backtrack
        }

        return ""; // If no valid string is found
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int> mp;
        for (auto& i : nums) mp[i]++;

        n = nums.size();
        return solve("", mp);
    }
};
