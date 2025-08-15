class Solution {
public:


    vector<int> numMovesStones(int a, int b, int c) {
                
              vector<int>check = {a,b,c};
              sort(check.begin(),check.end());
               vector<int>ans;
              if (check[1]-check[0]==1 &&check[2]-check[1]==1  ){
                     ans.push_back(0);
              }
              else if (check[1]-check[0]<=2 || check[2]-check[1]<=2  ){
                     ans.push_back(1);
              }
              else {
                    ans.push_back(2);
              }
         
              ans.push_back(check[2]-check[0]-2);
              return ans;
           
    }
};