class Solution {
public:
      
    vector<int>parent;

    int find(int x){
          
          if (parent[x]==x) return x;

          return parent[x]=find(parent[x]); 
    };
    
    void Union(int x,int y){
           
          parent[y]=x;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

         parent.resize(n);

         vector<int>cost(n,-1);

         for(int i=0;i<n;i++){
               parent[i]=i;
         }   

          for(auto &u:edges){
               
               int parentu=find(u[0]);
               int parentvs=find(u[1]);

               if (parentu!=parentvs) {
                   Union(parentu,parentvs);
                   cost[parentu]&=cost[parentvs];    
               }

               cost[parentu]&=u[2];
          }

          vector<int>result;

          for(auto  &q:query){
              
                int source=q[0];
                int destination=q[1];
                
                if (source==destination) result.push_back(0);
  else if (parent[find(source)]==parent[find(destination)]) result.push_back(cost[find(parent[source])]);
                else result.push_back(-1);
          }

          return result;
        
    }
};