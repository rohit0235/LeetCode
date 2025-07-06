class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
           int m =matrix.size();
           int n =matrix[0].size();
           vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        //  if (m==1 && matrix[0][0]=='0') return 0;
        //  if (m==1 && matrix[0][0]=='1') return 1;
        //    dp[0][0]=0;
           int maxSize=0;
           for(int i=0;i<m;i++){
              
                      for(int j=0;j<n;j++){
                          
                           if (matrix[i][j]=='1'){
                              
 dp[i + 1][j + 1] = 1+std::min(std::min(dp[i][j + 1], dp[i + 1][j]), dp[i][j]);
           
                    maxSize = std::max(maxSize, dp[i + 1][j + 1]);
                              
                           }
                                    
                          
                      } 

              
           }

           return  maxSize*maxSize;


    }
};