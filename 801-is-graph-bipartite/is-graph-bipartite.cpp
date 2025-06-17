class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        unordered_map<int, vector<int>> adj;

        // for (auto i : graph) {
        //     int u = i[0];
        //     int v = i[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        for(int i=0;i<n;i++){
              
              for(int j=0;j<graph[i].size();j++){
                      adj[i].push_back(graph[i][j]);
              }
              
        }

        vector<int> color(n, -1);

        queue<int> q;

        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {

                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int u = q.front();

                    q.pop();
                    for (auto v : adj[u]) {

                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }

                        else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};