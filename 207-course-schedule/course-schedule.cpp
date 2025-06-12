class Solution {
public:
    // bool solve(vector<int>& visited, vector<int>& dfsvisited,
    //            vector<vector<int>> &adj, int u) {

    //     visited[u] = true;
    //     dfsvisited[u] = true;

    //     for (int v : adj[u]) {

    //         if (!visited[v]) {
    //             if (solve(visited, dfsvisited, adj, v)) {
    //                 return true;
    //             }
    //         }

    //         if (dfsvisited[v]) {
    //             return true;
    //         }
    //     }

    //     dfsvisited[u] = false;
    //     return false;
    // }
    bool canFinish(int V, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(V);
          vector<int>indegree(V,0);
        for (auto& vec : prerequisites) {

            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
           
            indegree[u]++;
        }
       
         queue<int>q;
         int count=0;
       for (int i = 0; i < V; i++) { // Iterate through indices from 0 to V-1
            if (indegree[i] == 0) {
                q.push(i); // Push the course index 'i'
                count++;
            }
        }


         while (!q.empty()){
              
               int front =q.front();
                 q.pop();
               for(int& v:adj[front]){
                   
                    indegree[v]--;
                    if (indegree[v]==0) {
                         count++;
                         q.push(v);
                    }
                   
               }
         }

           return count==V;
      
        // dfs
        // vector<int> visited(V, 0);
        // vector<int> dfsvisited(V, 0);

        // for (int i = 0; i < V; i++) {
        //     if (!visited[i]) {
        //         if (solve(visited, dfsvisited, adj, i)){
        //                return false;
        //         }
                 
       
                
        //     }
        // }

        // return true;
    }
};