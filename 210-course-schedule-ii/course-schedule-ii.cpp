class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
         
            vector<vector<int>>adj(numCourses);
            vector<int>ans;
            vector<int>indegree(numCourses,0);
            for(auto i:pre){
                  int u = i[0];
                  int v = i[1];
                 adj[v].push_back(u);
                   indegree[u]++;
            }
            queue<int>q;
            for(int i=0;i<numCourses;i++){
                   if (indegree[i]==0){
                       q.push(i);
                            // ans.push_back(i);
                   }
            }
             
            int c =0;
            while (!q.empty()){
                    int u= q.front();
                    ans.push_back(u);
                    q.pop();
                  c++;
                  for(auto v:adj[u]){
                     indegree[v]--;
                     if (indegree[v]==0){
                         q.push(v);
                     }
                  }
                   
            }
            
        if ( c==numCourses) return ans;
        return {}; 
    }
};