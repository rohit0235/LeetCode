class Solution {
public:
    vector<string> cs;
    vector<vector<int>> adj;
    int dp[5001][13];
    const int mod = 1e9 + 7;

    void generate(string curr, char prev, int n, int idx) {
        if (idx == n) {
            cs.push_back(curr);
            return;
        }

        for (char c : {'R', 'G', 'B'}) {
            if (c == prev) continue;
            generate(curr + c, c, n, idx + 1);
        }
    }

    int solve(int rem, int prev) {
        if (rem == 0) return 1;

        int &ans = dp[rem][prev];
        if (ans != -1) return ans;

        ans = 0;
        for (int nxt : adj[prev]) {
            ans = (ans + solve(rem - 1, nxt)) % mod;
        }
        return ans;
    }

    int numOfWays(int n) {
        memset(dp, -1, sizeof(dp));

        generate("", '#', 3, 0);   // column height fixed = 3
        int k = cs.size();

        // Precompute valid transitions
        adj.assign(k, vector<int>());
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                bool ok = true;
                for (int r = 0; r < 3; r++) {
                    if (cs[i][r] == cs[j][r]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) adj[i].push_back(j);
            }
        }

        int res = 0;
        for (int i = 0; i < k; i++) {
            res = (res + solve(n - 1, i)) % mod;
        }

        return res;
    }
};
