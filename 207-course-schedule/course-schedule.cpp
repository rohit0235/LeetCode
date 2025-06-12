class Solution {
public:
    bool solve(vector<int>& visited, vector<int>& dfsvisited,
               vector<vector<int>> &adj, int u) {

        visited[u] = true;
        dfsvisited[u] = true;

        for (int v : adj[u]) {

            if (!visited[v]) {
                if (solve(visited, dfsvisited, adj, v)) {
                    return true;
                }
            }

            if (dfsvisited[v]) {
                return true;
            }
        }

        dfsvisited[u] = false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(V);

        for (auto& vec : prerequisites) {

            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
        }

        vector<int> visited(V, 0);
        vector<int> dfsvisited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (solve(visited, dfsvisited, adj, i)){
                       return false;
                }
                 
       
                
            }
        }

        return true;
    }
};