class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        // using kahn algo
 
            vector<vector<int>>adj(numCourses);
       
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
                   }
            }
             
            int c =0;
            while (!q.empty()){
                int u= q.front();
                q.pop();
                  c++;
                  for(auto v:adj[u]){
                     indegree[v]--;
                     if (indegree[v]==0){
                         q.push(v);
                     }
                  }
                   
            }

            return c==numCourses;
    }
};