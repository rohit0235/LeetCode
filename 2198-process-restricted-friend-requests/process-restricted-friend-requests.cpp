class Solution {
public:
    vector<int> parentf;

    int find(int x) {
        if (parentf[x] == x) return x;
        return parentf[x] = find(parentf[x]);
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry)
            parentf[rx] = ry;
    }

    vector<bool> friendRequests(int n,
        vector<vector<int>>& restrictions,
        vector<vector<int>>& requests) {

        parentf.resize(n);
        for (int i = 0; i < n; i++)
            parentf[i] = i;

        vector<bool> ans;

        for (auto &req : requests) {
            int u = req[0];
            int v = req[1];

            int ru = find(u);
            int rv = find(v);

            bool ok = true;

            if (ru != rv) {
                for (auto &r : restrictions) {
                    int a = r[0], b = r[1];
                    int ra = find(a);
                    int rb = find(b);

                    // After union, would restriction break?
                    if ((ra == ru && rb == rv) ||
                        (ra == rv && rb == ru)) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok) {
                unite(u, v);
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};
