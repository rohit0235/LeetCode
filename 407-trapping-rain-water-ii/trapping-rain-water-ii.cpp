class Solution {
public:
    #define p pair<int, pair<int, int>>
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        if (n < 3 || m < 3) return 0; // No water can be trapped in less than 3x3 grids.

        // Priority queue to store heights along with their coordinates
        priority_queue<p, vector<p>, greater<p>> pq;

        // Visited array to keep track of processed cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Push all boundary cells into the priority queue
        for (int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m - 1], {i, m - 1}});
            visited[i][0] = true;
            visited[i][m - 1] = true;
        }
        for (int j = 0; j < m; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[n - 1][j], {n - 1, j}});
            visited[0][j] = true;
            visited[n - 1][j] = true;
        }

        int vol = 0; // To store total water trapped
        int dRow[4] = {-1, 0, 1, 0}; // Row movement directions
        int dCol[4] = {0, 1, 0, -1}; // Column movement directions

        // Process the cells in the priority queue
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();

            int height = front.first;
            int row = front.second.first;
            int col = front.second.second;

            // Visit all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                // Check bounds and if the cell is unvisited
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol]) {
                    // Calculate trapped water
                    vol += max(0, height - heightMap[nRow][nCol]);

                    // Update boundary height and push to queue
                    pq.push({max(height, heightMap[nRow][nCol]), {nRow, nCol}});

                    // Mark as visited
                    visited[nRow][nCol] = true;
                }
            }
        }

        return vol; // Return total trapped water
    }
};