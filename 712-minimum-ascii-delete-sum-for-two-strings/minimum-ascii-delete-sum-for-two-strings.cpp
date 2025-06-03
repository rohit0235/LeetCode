class Solution {
public:
     int m,n;
     
     int solve(string &s1 , string& s2 , int i , int j,  vector<vector<int>>&dp){
            if (i>=m && j>=n) return 0;\
            if (dp[i][j]!=-1) return dp[i][j];
            if (i>=m) {
                 return s2[j]+solve(s1,s2,i,j+1,dp); 
            }
            if (j>=n) {
                 return s1[i] +solve(s1,s2,i+1,j,dp);
            }
            if (s1[i]==s2[j]){
                 return solve(s1,s2,i+1,j+1,dp);
            }

            int d1=s1[i]+ solve(s1,s2, i+1 ,j,dp);
            int d2=s2[j]+ solve(s1,s2, i ,j+1,dp);
            
            return dp[i][j]=min(d1,d2);
     }

    int minimumDeleteSum(string s1, string s2) {
           
         m= s1.size();       
         n= s2.size();       
         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
         return solve(s1,s2,0,0,dp);
    }
};