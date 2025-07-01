class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int m = points.size();
        int n = points[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {

            unordered_map<double, int> mp;

            int f1 = points[i][0];
            int s1 = points[i][1];
            for (int j = i + 1; j < m; j++) {

                int f2 = points[j][0];
                int s2 = points[j][1];

                int num = (s2 - s1);
                int den = f2 - f1;

                //    if (num==0) mp[0.0]++;
                if (den == 0)
                    mp[INT_MAX]++;
                else {
                    double slope = (double)num / den;

                    mp[slope]++;
                }
            }
            int maxi = 0;
            for (auto i : mp) {

                maxi = max(maxi, i.second);
            }

            ans = max(ans, maxi + 1);
        }

        return ans;
    }
};