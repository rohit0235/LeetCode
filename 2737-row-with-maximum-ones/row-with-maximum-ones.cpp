class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
             
              int n =mat.size();
              int m=mat[0].size();
              vector<int>ans(2,0);
              for(int i=0;i<n;i++){
                 
                     int  c= 0;
                    for(int j=0;j<m;j++){
                          if (mat[i][j]==1) c++;
                           
                    }

                    if (c>ans[1]){
                    
                        ans[0]=i;
                        ans[1]=c;
                        //  ans.push_back(c);

                    }
                   
              }
              return ans;
    }
};