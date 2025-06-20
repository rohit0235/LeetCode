class Solution {
public: 



         void Unite(int x , int y,vector<int>&parent ){
             
                 int lf = find(x,parent);
                 int jf = find(y,parent);
                
                  if (lf != jf) { 
                        parent[lf] = jf; // Make root of x's set point to root of y's set
                    }
         }
                 int find(int x ,vector<int>&parent){
                   
                   if (parent[x]==x) return x;
                   
                   return parent[x]=find(parent[x],parent);
          }


    int makeConnected(int n, vector<vector<int>>& connections) {
          
        
            // unordered_map <int,vector<int>>adj;

            // for(int i=0;i<connections.size();i++){
                  
            //         int first =connections[i][0];
            //         int second =connections[i][1];
                    
            //         adj[first].push_back(second);
            // }
vector<int>parent(n,0);

             if (n-1>connections.size()) return -1;
    
            for(int i=0;i<n;i++) 
                parent[i]=i;
           
             int com=n;
       
             for(auto &vec:connections){
                  
                   if (find(vec[0],parent)!=find(vec[1],parent)){
                           com--;
                           Unite(vec[0],vec[1],parent);

                   }
                  
             }

             return com-1;
      


           
    }
};