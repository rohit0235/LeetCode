class Solution {
public:
    bool dfs(int& u, int& v, unordered_map<int, vector<int>>& adj,
             vector<bool>& visited) {
                  
                     visited[u]=1;
                     if (u==v) return true;

                     for(auto &check:adj[u]){
                          if (visited[check]) continue;
                          if (dfs(check,v,adj,visited)){
                              return true;
                          }
                     }

                     return false;


             }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            vector<bool> visited(n, false);
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() &&
                dfs(u, v, adj, visited)) {
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //  map<vector<int>,int>mp;
        //  for (auto i:edges){
        //      mp[i]++;
        //  }
        //    int n =edges.size();
        //    int m=edges[0].size();
        // for (int i=0;i<n;i++){

        //      for (int j=i+1;j<n;j++){

        //         if (edges[i][0] == edges[j][0]){
        //               if (mp.count({edges[i][1],edges[j][1]})){
        //                    return {edges[i][1],edges[j][1]};
        //               }
        //         }
        //         else if (edges[i][1] == edges[j][0]){
        //                if (mp.count({edges[i][0],edges[j][1]})){
        //                    return {edges[i][0],edges[j][1]};
        //               }
        //         }

        //      }
        // }
        return {-1,-1};
    }
};