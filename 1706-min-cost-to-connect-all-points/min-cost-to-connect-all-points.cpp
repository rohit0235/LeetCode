class Solution {
public:
    int find(vector<int>&parent , int x ){
         if (parent[x]==x) return x;
         return parent[x] = find(parent, parent[x]);
    }
    void unite(vector<int>&parent , int x , int y){
        int lrep = find(parent,x);
        int jrep = find(parent,y);
        parent[lrep]= jrep;
   
    }
    static bool cmp(vector<int>&a , vector<int>&b){
            return a[2]<b[2];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
           int n = points.size();
           vector<int>parent(n,0);
           for(int i=0;i<n;i++){
             parent[i]=i;
           } 

            vector<vector<int>>c;

           for(int i=0;i<n;i++){
                                        
                  for(int j=i+1;j<n;j++){
       int cost = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                  c.push_back({i,j,cost});
                  }
           }           
          sort(c.begin(),c.end(),cmp);
          int totalcost =0;
           for(int i=0;i<c.size();i++){
                        
                       int x = c[i][0];
                       int y = c[i][1];
                       int curr = c[i][2];
                      if (find(parent, x)!=find(parent, y)){
                            totalcost+=curr;
                            unite(parent, x , y);
                      }
             
           }   

           return totalcost;        
    }
};