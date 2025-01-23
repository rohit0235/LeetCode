class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
          unordered_map<int, int> rowCount, colCount;
    int rows = grid.size();
    int cols = grid[0].size();

    // Count number of 1's in each row and column
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }

    // Calculate the total while avoiding double counting
    int total = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                if (rowCount[i] > 1 || colCount[j] > 1) {
                    total++;
                }
            }
        }
    }

    return total;

        
    }
};