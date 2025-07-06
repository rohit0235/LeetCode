class Solution {
public:
    int n;
    int dp[201][201];
     int solve (vector<vector<int>>& triangle ,  int i , int j ){
          
              if (i>=n ) return 0;
            // sum+=triangle[i][j];
            //  int first =0;
            //   int second =0;
             if (dp[i][j]!=-1) return dp[i][j];
           int first  =triangle[i][j]+ solve(triangle,i+1,j); 
          int second  = triangle[i][j]+ solve(triangle,i+1,j+1);

              return dp[i][j]=min(first,second);

 
           
             
     }
    int minimumTotal(vector<vector<int>>& triangle) {
           memset(dp,-1, sizeof(dp));
             n= triangle.size();
            return solve(triangle, 0,0);
        
          

    }
}; 