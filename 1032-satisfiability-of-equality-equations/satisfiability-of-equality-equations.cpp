class Solution {
public:
      vector<int>parent;
       int find (int x){
              if (parent[x]==x) return x;

              return parent[x]=find(parent[x]);
       }

       void unions(int x , int y){
              
              int lrep =find(x);
              int jrep =find(y);

              parent[lrep]=jrep;
              return ;
            
       }
 

    bool equationsPossible(vector<string>& equations) {
             int n =equations.size();  
             parent.resize(26,0);
       
           
           for(int i=0;i<26;i++){
             parent[i]=i;
           }

           for(int i=0;i<n;i++){
                    
                   
                        char first =equations[i][0];
                        char second =equations[i][3];


                        if (equations[i][1]=='='){
                              
                              unions(first-'a',second-'a');
                              
                        }
                        

           }

           for(int i=0;i<n;i++){
                    
                   
                        char first =equations[i][0];
                        char second =equations[i][3];


                        if (equations[i][1]=='!'){
                              
                              int c=find(first-'a');
                              int d=find(second-'a');
                              if (c==d) return false;
                            //   unions(first-'a',second-'a');
                              
                        }
                        

           }

           return true;

    }
};