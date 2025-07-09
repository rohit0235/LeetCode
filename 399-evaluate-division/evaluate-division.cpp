class Solution {
public:
 
 void dfs(unordered_map<string , vector<pair<string,double>>>&adj,string num ,  string den,double maxi , double& ans ,  unordered_set<string>&visited) {
     
      if (visited.find(num)!=visited.end())  return;

      if (num==den) {
         ans=maxi ;
         return ;
      }
     visited.insert(num);
      for(auto  &p:adj[num]){
          
                   string j = p.first;
                   double v = p.second;

                   dfs(adj, j , den , maxi*v, ans , visited);
          
      }
       
        
 }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            
               int n =values.size();

               unordered_map<string , vector<pair<string,double>>>adj;
              
              for(int i=0;i<n;i++){
                 
                     string key = equations[i][0];
                     string val = equations[i][1];

                     double va=values[i];

                     adj[key].push_back({val,va});
                     adj[val].push_back({key,1.0/va});
                   
              }
               int k =queries.size();
               vector<double>result;
              for(auto  i :queries){
                    
                     string num = i[0];
                     string den = i[1];


                     if (adj.find(num)!=adj.end()){
                            
                            double maxi=1.0;
                            double ans=-1.0;
                             unordered_set<string>visited;
                             dfs(adj , num , den , maxi  , ans, visited);
 
                              result.push_back(ans);

                     }

                     else{
                           result.push_back(-1.0);
                     }
                  
              }

              return result;


    }
};