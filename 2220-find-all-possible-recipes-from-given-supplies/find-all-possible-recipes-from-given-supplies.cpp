class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
          
          unordered_set<string>st;
          vector<string>ans;
          for(auto &i:supplies) st.insert(i); 
          int n=ingredients.size();
          vector<bool>available(n,0);
         
         int count=n;
        while (count--){
          for(int i=0;i<n;i++){

                if (available[i]==true){
                     continue;
                }
                bool find=true;
               for(int j=0;j<ingredients[i].size();j++){

                     if (st.find(ingredients[i][j])==st.end()) {
                          find=false;
                          break;
                     }   
                    
               }   

               if (find){
                  ans.push_back(recipes[i]);
                  st.insert(recipes[i]);
                  available[i]=true;
               }


          } 
        }
          return ans;

    }
};