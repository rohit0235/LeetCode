class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

                int n =graph.size();            
               vector<vector<int>>revgraph(n);
                
                vector<int>outdeg(n,0);
               for(int i=0;i<n;i++){
                 
                        for(auto neigh :graph[i]){
                              revgraph[neigh].push_back(i);
                        }
                        
                        outdeg[i]=graph[i].size();


               }


                queue<int>q;
                for(int i=0;i<n;i++){
                     if (outdeg[i]==0) q.push(i);
                }

                vector<int>result;

                while (!q.empty()){
                         

                       int top =q.front();  q.pop();
                       result.push_back(top);
                  
                       for(auto j:revgraph[top]){
                         
                                 outdeg[j]--;
                                 if (outdeg[j]==0){ 
                                      q.push(j);

                                 }
                           
                       }
                       
                }
                       sort(result.begin(),result.end());
                return result;






    }
};