class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {

        int m = arr.size();
        int n = arr[0].size();

        int i = 0;
        int j = m - 1;

        while (i <= j) {

            int mid = i + (j - i) / 2;

            if ((arr[mid][0] <= target )&& (arr[mid][n - 1] >= target)) {

                int l = 0;
                int r = n - 1;

                while (l <= r) {

                    int mid1 = l + (r - l) / 2;
                    // cout<<midd<<"  "<<mid1<<" "<<endl;
                    if (arr[mid][mid1] == target)
                        return true;
                    else if (arr[mid][mid1] < target) {
                        l = mid1 + 1;
                    } else {
                        r = mid1 - 1;
                    }
                }
                return false;

            }

           else  if (arr[mid][0] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

                return false;



    }
};