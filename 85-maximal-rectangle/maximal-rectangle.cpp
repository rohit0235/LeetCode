class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int maxA = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxA = max(maxA, h * w);
            }
            s.push(i);
        }
        heights.pop_back();
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int numCols = matrix[0].size();
        vector<int> heights(numCols, 0);
        int maxArea = 0;

        for (const auto& row : matrix) {
            for (int col = 0; col < numCols; ++col) {
                if (row[col] == '1') {
                    heights[col]++;
                } else {
                    heights[col] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};