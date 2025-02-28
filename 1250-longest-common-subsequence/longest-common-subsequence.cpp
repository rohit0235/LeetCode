class Solution {
public:
     int solve(string &text1, string &text2,int i,int j,   vector<vector<int>>&memo){
                
                if (i==0 || j==0){
                     return 0;
                }
            if (memo[i][j]!=-1) return memo[i][j];                  else if (text1[i-1]==text2[j-1]){
                   return memo[i][j]= 1+solve(text1,text2,i-1,j-1,memo);
                 }

     return memo[i][j]=max(solve(text1,text2,i-1,j,memo),solve(text1,text2,i,j-1,memo));
              
                
     }
      
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        vector<vector<int>>memo(n+1,vector<int>(m+1,0));
        // return solve(text1,text2,n,m,memo);
          
        for(int i=1;i<=n;i++){
                
                for(int j=1;j<=m;j++){
                     
                     if (text1[i-1]==text2[j-1]){
                          
                          memo[i][j]=1+memo[i-1][j-1];
                     }
                     else{
                          memo[i][j]=max(memo[i][j-1],memo[i-1][j]);
                     }
                }
        }

        return memo[n][m];

    }
};