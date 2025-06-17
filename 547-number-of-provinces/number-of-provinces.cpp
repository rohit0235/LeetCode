class Solution {
public:

       void dfs(vector<vector<int>>& isConnected,int u,vector<bool>&visited,   vector<vector<int>>adj)
{  

        visited[u]=true;

       for(auto v:adj[u]){
             
                if (!visited[v]){
                       
                       dfs(isConnected,v,visited,adj);
                      
                }
           
       }



     
         
}

    int findCircleNum(vector<vector<int>>& isConnected) {
             
              int n =isConnected.size();
              int m =isConnected[0].size();
               int ans =0;
               
               vector<vector<int>>adj(n,vector<int>(m,0));

               for(auto i=0;i<isConnected.size();i++){
                        
                        for(int j=0;j<isConnected[0].size();j++){
                              
                              if (isConnected[i][j]==1){
                                     adj[i].push_back(j);
                                     adj[j].push_back(i);
                                  
                              }


                        }

                   
               }
               vector<bool>visited(n,0);
              for(int i=0;i<n;i++){
                  
                    if (!visited[i]){
                            ans++;
                         dfs(isConnected , i , visited,adj);
                         
                    }
             
                  
              }


              return ans ;

              
    }
};