class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        vector<bool> check(n, false); // Tracks safe nodes
        vector<int> outdegree(n, 0); // Tracks outgoing edges
        vector<vector<int>> reverseGraph(n); // Stores reversed graph edges
        
        // Step 1: Build reverse graph and calculate outdegree
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
            }
            outdegree[i] = graph[i].size();
        }

        // Step 2: Identify nodes with zero outdegree (safe nodes)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
                check[i] = true;
            }
        }

        // Step 3: Process reverse graph to mark all safe nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : reverseGraph[node]) {
                outdegree[neighbor]--;
                if (outdegree[neighbor] == 0) {
                    q.push(neighbor);
                    check[neighbor] = true;
                }
            }
        }

        // Step 4: Sort result and return
        sort(result.begin(), result.end());
        return result;
    }
};
