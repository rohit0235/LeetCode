class Solution {
public:
    vector<string> ans;

    bool issafe(string check) {
        if (check[0] == '0')
            return false;

        int val = stoi(check);
        return val <= 255;
    }
    int n;
    void solve(int idx, int part, string curr, string& s) {

        if (idx == n && part == 4) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        if (idx + 1 <= n) {
            solve(idx + 1, part + 1, curr + s.substr(idx, 1)+".", s);
        }
        if (idx + 2 <= n && issafe(s.substr(idx, 2))) {
            solve(idx + 2, part + 1, curr + s.substr(idx, 2)+".", s);
        }
        if (idx + 3 <= n && issafe(s.substr(idx, 3))) {
            solve(idx + 3, part + 1, curr + s.substr(idx, 3)+".", s);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        string curr = "";
        solve(0, 0, curr, s);

        return ans;
    }
};