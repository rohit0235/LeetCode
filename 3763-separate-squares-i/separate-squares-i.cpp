class Solution {
public:
    double ispos(vector<vector<int>>& sq, double mid) {
        double total = 0.00000;
        for (auto& i : sq) {
            double y = i[1];
            double h = i[2];
            if (mid > y) {
                double height = min(mid, y + h) - y;
                total += height * h;
            }
        }
        return total;
    }

    double separateSquares(vector<vector<int>>& sq) {
        double totalarea = 0.00000;
        double l = 1e18, r = -1e18;

        for (auto& i : sq) {
            totalarea += 1.0 * i[2] * i[2];
            l = min(l, (double)i[1]);
            r = max(r, (double)(i[1] + i[2]));
        }

        double search = totalarea / 2.00000;
        double ans = r;

        for (int i = 0; i < 100; i++) {
            double mid = l + (r - l) / 2.00000;
            double check = ispos(sq, mid);

            if (check >= search) {
                ans = mid;
                r = mid;
            } else {
                l = mid;
            }
        }

        return ans;
    }
};