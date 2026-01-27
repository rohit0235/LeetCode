class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int>dist(n,INT_MAX);
        
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:edges){
              int u = i[0];
              int v = i[1];
              int w = i[2];

              adj[u].push_back({v,w}); 
              adj[v].push_back({u,w*2});
        }
    
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        // weight and point
        pq.push({0,0});
        dist[0]=0;
        while (!pq.empty()){
               
                auto top = pq.top();
                int d= top.first;
                int u = top.second;
               pq.pop();
                for(auto pair:adj[u]){
                        
                         int v2= pair.first;
                         int w2= pair.second;
                    
                    if(dist[u]!=INT_MAX && dist[u]+w2<dist[v2]){
                          dist[v2]= dist[u]+w2;
                          pq.push({dist[v2],v2});
                    }



                }
        }
    
        if(dist[n-1]==INT_MAX) return -1;
        return dist[n-1];



    }
};