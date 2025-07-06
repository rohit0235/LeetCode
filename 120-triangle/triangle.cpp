class Solution {
public:
    // int n;
    // int dp[201][201];
    //  int solve (vector<vector<int>>& triangle ,  int i , int j ){
          
    //           if (i>=n ) return 0;
    //         // sum+=triangle[i][j];
    //         //  int first =0;
    //         //   int second =0;
    //          if (dp[i][j]!=-1) return dp[i][j];
    //        int first  =triangle[i][j]+ solve(triangle,i+1,j); 
    //       int second  = triangle[i][j]+ solve(triangle,i+1,j+1);

    //           return dp[i][j]=min(first,second);

 
           
             
    //  }
    int minimumTotal(vector<vector<int>>& triangle) {
      
            int n = triangle.size();
            int m = triangle[n-1].size();
      
            vector<vector<int>>dp(n,vector<int>(m,1e9));
            dp[0][0] = triangle[0][0];
            for( int i = 1; i < n;i++){
                for( int j = 0; j < triangle[i].size();j++){
                    if(j <= triangle[i-1].size()){
                        dp[i][j] = min(dp[i][j],triangle[i][j]+dp[i-1][j]);
                    }
                    if( j-1 >= 0){
                        dp[i][j] = min(dp[i][j],triangle[i][j]+dp[i-1][j-1]);
                    }
                }
            }

            int res = INT_MAX;

            for( int i = 0; i < triangle[n-1].size();i++){
                res = min(res,dp[n-1][i]);
            }

            return res;
        
          

    }
}; 