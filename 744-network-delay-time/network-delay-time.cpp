class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
                   
              vector<int>dist(n+1,INT_MAX);

              vector<vector<vector<int>>> adj(n+1); 

                for (const auto &edge : times) {
                    int u = edge[0];
                    int v = edge[1];
                    int wt = edge[2];
                    adj[u].push_back({v, wt});
                    // adj[v].push_back({u, wt}); 
                }
                


              priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
              dist[k]=0;
              pq.push({dist[k],k});
      
        


              while (!pq.empty()){
                  
                       int w=pq.top()[0];
                       int u =pq.top()[1];
                       pq.pop();
                       for(auto x:adj[u]){
                             
                             int v =x[0];
                             int w =x[1];
                             if (dist[v]>dist[u]+w){
                                 
                                    dist[v]=dist[u]+w;
                                    pq.push({dist[v],v});
                             }
                       } 
              }

              int maxi =0;
              for(int i=1;i<dist.size();i++){
                 maxi =max(maxi,dist[i]);
               }
              if (maxi==INT_MAX) return -1;
           return maxi;

              

    }
};