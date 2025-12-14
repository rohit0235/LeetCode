class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //    int n = edges.size();
        //    int m = edges[0].size();
           vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
           for(auto i:edges){
                  int u = i[0];
                  int v= i[1];
                  int w = i[2];
                  dist[u][v] = w;
                  dist[v][u] = w;
           }
           for(int i=0;i<n;i++)dist[i][i]=0;
           for(int k=0;k<n;k++){
                   
                   for(int i=0;i<n;i++){
                      for(int j=0;j<n;j++){
                        if (dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                           dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

                      }
                   }
           }
        
           int ans =0;
           int mini =INT_MAX;

        for(int i=0;i<n;i++){
              int curr =0;
            for(int j=0;j<n;j++){
                // cout<<dist[i][j]<<" ";
               if (j!=i && dist[i][j]<=distanceThreshold){
                    curr++;
               }

            }
            // cout<<endl;
            // cout<<mini<<" "<<curr<<endl;
            if (mini>=curr){ 
                  ans = i;
                  mini = curr;
            }
        }

        return ans;

            
    }
};