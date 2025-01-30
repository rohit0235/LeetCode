class Solution {
public:
    bool isBipartite = true;
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> color(n + 1, 0), connectedNodes;
        int maxGroups = 0;
        for (int i = 1; i <= n; i++) {
            if (!color[i]) {
                connectedNodes = vector<int>();
                isBipartite = true;
                dfs(i, 1, adj, color, connectedNodes);
                if (!isBipartite)
                    return -1;
                int maxFromComponents = 0;
                for (auto it : connectedNodes) {
                    maxFromComponents =
                        max(maxFromComponents, getMaxFromNode(it, n, adj));
                }
                maxGroups += maxFromComponents;
            }
        }
        return maxGroups;
    }
    void dfs(int node, int currcolor, vector<vector<int>>& adj,
             vector<int>& color, vector<int>& connectedNodes) {
        color[node] = currcolor;
        connectedNodes.push_back(node);
        for (auto it : adj[node]) {
            if (!color[it])
                dfs(it, 3 - currcolor, adj, color, connectedNodes);
            else if (color[it] == currcolor)
                isBipartite = false;
        }
    }
    int getMaxFromNode(int node, int n, vector<vector<int>>& adj) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(node);
        dist[node] = 1;
        int mdist = 1;
        while (!q.empty()) {
            auto cnode = q.front();
            q.pop();
            for (auto it : adj[cnode]) {
                if (dist[it] == -1) {
                    dist[it] = dist[cnode] + 1;
                    q.push(it);
                    mdist = max(mdist, dist[it]);
                }
            }
        }
        return mdist;
    }
};