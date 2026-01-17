class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        long long ms = 0;
        int n = bl.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = max(bl[i][0], bl[j][0]);
                int x2 = min(tr[i][0], tr[j][0]);
                int y1 = max(bl[i][1], bl[j][1]);
                int y2 = min(tr[i][1], tr[j][1]);
                
                if (x2 > x1 && y2 > y1) {
                    long long s = min(x2 - x1, y2 - y1);
                    ms = max(ms, s);
                }
            }
        }
        return ms * ms;
    }
};