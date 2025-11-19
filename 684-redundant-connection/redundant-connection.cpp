class Solution {
public:
    
    int find(int i, vector<int>&parent){
           if (parent[i]==i) return i;
           return parent[i]= find(parent[i],parent);
    }
    void unite(int i,int j,vector<int>&parent){
           int lrep = find(i,parent);
           int jrep = find(j,parent);
           parent[lrep] = jrep;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
                   int n = edges.size()+1;
                   vector<int>parent(n+1,0);
            for(int i=1;i<n;i++){
                 parent[i]=i;
            }
               vector<int>ans;
            for(auto i:edges){
                  int u = i[0];
                  int v = i[1];
                  if (find(u,parent)!=find(v,parent)){
                       unite(u,v,parent);
                  }
                  else{
                      ans =i;
                  }
            }
            return ans;

    } 
};