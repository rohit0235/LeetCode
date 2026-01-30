class Solution {
public:
    const long long INF = 1e18;

    struct Trie {
        int nxt[26];
        int id;
        Trie() {
            memset(nxt, -1, sizeof(nxt));
            id = -1;
        }
    };

    vector<Trie> trie;

    void insert(string &s, int idx) {
        int node = 0;
        for (char c : s) {
            int x = c - 'a';
            if (trie[node].nxt[x] == -1) {
                trie[node].nxt[x] = trie.size();
                trie.push_back(Trie());
            }
            node = trie[node].nxt[x];
        }
        trie[node].id = idx;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        unordered_map<string,int> mp;
        int id = 0;

        for (int i = 0; i < original.size(); i++) {
            if (!mp.count(original[i])) mp[original[i]] = id++;
            if (!mp.count(changed[i])) mp[changed[i]] = id++;
        }

        int m = id;
        vector<vector<long long>> dist(m, vector<long long>(m, INF));

        for (int i = 0; i < m; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        trie.clear();
        trie.push_back(Trie());

        for (auto &p : mp)
            insert(const_cast<string&>(p.first), p.second);

        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            int node = 0;
            for (int j = i; j < n; j++) {
                int c = source[j] - 'a';
                if (trie[node].nxt[c] == -1) break;
                node = trie[node].nxt[c];

                if (trie[node].id != -1) {
                    int u = trie[node].id;
                    int len = j - i + 1;
                    if (i + len > n) continue;

                    string t = target.substr(i, len);
                    if (!mp.count(t)) continue;

                    int v = mp[t];
                    long long cst = dist[u][v];
                    if (cst < INF)
                        dp[i] = min(dp[i], cst + dp[i + len]);
                }
            }
        }

        return dp[0] >= INF ? -1 : dp[0];
    }
};
