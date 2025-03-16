class Solution {
public:
       bool ispalind(string &s,int i,int j,vector<vector<int>>&dp){
              
              if (i>=j) return 1;
                if (dp[i][j]!=-1) return dp[i][j];
              if (s[i]==s[j]) return dp[i][j]=ispalind(s,i+1,j-1,dp);

              return dp[i][j]==0;
       }
    string longestPalindrome(string s) {
              int n=s.size();
              int sp=0;
              int maxlen=INT_MIN;
              vector<vector<int>>dp(n,vector<int>(n,-1));
             for(int i=0;i<n;i++){
                   
                     for(int j=i;j<n;j++){
                          
                           if (ispalind(s,i,j,dp)){
                                 if (j-i+1>maxlen){
                                       maxlen=j-i+1;
                                       sp=i;
                                 }
                           }
                     }
             }

             return s.substr(sp,maxlen);
    }
};