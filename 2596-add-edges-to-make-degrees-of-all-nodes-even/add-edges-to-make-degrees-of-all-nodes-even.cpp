class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n + 1, 0);
        unordered_set<long long> st;

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            deg[u]++;
            deg[v]++;
            st.insert((long long)u * 100000 + v);
            st.insert((long long)v * 100000 + u);
        }

        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (deg[i] % 2 == 1)
                odd.push_back(i);
        }

        if (odd.size() == 0) return true;
        if (odd.size() > 4) return false;

        auto exists = [&](int a, int b) {
            return st.count((long long)a * 100000 + b);
        };

        if (odd.size() == 2) {
            int a = odd[0], b = odd[1];
            if (!exists(a, b)) return true;

            for (int x = 1; x <= n; x++) {
                if (x != a && x != b &&
                    !exists(a, x) && !exists(b, x))
                    return true;
            }
            return false;
        }

        // odd.size() == 4
        int a = odd[0], b = odd[1], c = odd[2], d = odd[3];

        if (!exists(a, b) && !exists(c, d)) return true;
        if (!exists(a, c) && !exists(b, d)) return true;
        if (!exists(a, d) && !exists(b, c)) return true;

        return false;
    }
};
