class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         // src is k
         // using djisktra 

         vector<int>dist(n+1,INT_MAX);
         unordered_map<int,vector<pair<int,int>>>adj;
         for(auto i:times){
             int u = i[0];
             int v = i[1];
             int w = i[2];
              adj[u].push_back({v,w});
          }

          dist[k]=0;
          priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
          q.push({k , 0});
          while (!q.empty()){
               
               pair<int,int>front = q.top();
               int u = front.first;
               int cost = front.second;
               q.pop();
               for(auto p:adj[u]){
                 
                    int v=  p.first;
                    int d=  p.second;
                    if (cost!=INT_MAX && d!=INT_MAX &&  dist[v]>d+cost){
                         dist[v] = d+cost;
                         q.push({v,dist[v]});
                    }
               }
          }
         
          int mini = 0;
          for(int i=1;i<dist.size();i++){
             if (dist[i]==0) continue;
              if (dist[i]==INT_MAX) return -1;
              mini = max(mini, dist[i]);
          }
          return mini;
         
    }
};