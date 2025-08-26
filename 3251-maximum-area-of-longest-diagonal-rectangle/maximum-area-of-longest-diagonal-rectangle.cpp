class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        long long maxd = LLONG_MIN;
        int ans = 0;

        for (auto i : dimensions) {

            long long curr =
                ((long long)i[0] * i[0]) + ((long long)i[1] * i[1]);

            if (curr > maxd) {
                // A new maximum diagonal is found, update both maxd and ans
                maxd = curr;
                ans = i[0] * i[1];
            } else if (curr == maxd) {
                // Diagonal is the same, but check if the area is larger
                int current_area = i[0] * i[1];
                if (current_area > ans) {
                    ans = current_area;
                }
            }
        }

        return ans;
    }
};