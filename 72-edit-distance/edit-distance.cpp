class Solution {
public:

    int solve(string &word1,string &word2,int i,int j,  vector<vector<int>>&dp){
             int m=word1.size();
             int n=word2.size();
            if (i==word1.size()){
                  return n-j;
            }
            if (j==n){
                  return m-i;
            }
            if (word1[i]==word2[j]){
                return  solve(word1,word2,i+1,j+1,dp);
            }

            if (dp[i][j]!=-1) return dp[i][j];
             int insert=1+solve(word1,word2,i,j+1,dp);
             int deletes=1+solve(word1,word2,i+1,j,dp);
             int replace=1+solve(word1,word2,i+1,j+1,dp);

            return dp[i][j]=min(insert,min(deletes,replace));





     }
    int minDistance(string word1, string word2) {
           vector<vector<int>>dp(501,vector<int>(501,-1));
           return solve(word1,word2,0,0,dp);
    }
};