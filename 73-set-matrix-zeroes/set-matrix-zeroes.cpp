class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
               
              
                int n=matrix.size();
                int m=matrix[0].size();
                 vector<bool>c(m,0);
                 vector<bool>r(n,0);
                for(int i=0;i<n;i++){
                      
                      for(int j=0;j<m;j++){
                             if (matrix[i][j]==0){
                                   
                                   c[j]=1;
                                   r[i]=1;


                             }
                             
                      }
                }
                for(int i=0;i<n;i++){
                      
                      for(int j=0;j<m;j++){
                             if (c[j]==1 || r[i]==1){
                                   matrix[i][j]=0;
                             }
                             
                      }
                }




    }
};