class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> dist(n, INT_MAX);
        unordered_map<int, vector<pair<int,int>>> adj;
        for (auto i : flights) {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v, w});
        }

        dist[src] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        int steps = 0;
        while (!q.empty() && steps <= k) {

            int n = q.size();
            while (n--) {
                pair<int, int> p = q.front();
                q.pop();
                int u = p.first;
                int cost = p.second;
                for(auto p:adj[u]){
                       
                       if (dist[p.first]>p.second+cost){
                           dist[p.first] =p.second+cost;
                           q.push({p.first,dist[p.first]});
                       }
                       
                }
            }
            steps++;
        }

        if (dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};