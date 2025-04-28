class Solution {
public:

     int n;
     int m;
     int t[1001][1001];
    int solve(string &text1, string &text2,int i,int j){
          
          if (i==n || j==m ) return 0;
          if (t[i][j]!=-1) return t[i][j];
         if (text1[i]==text2[j]){
               return t[i][j]=1+solve(text1,text2,i+1,j+1);
         }

         else{
             return t[i][j]=max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
         }


    }



    int longestCommonSubsequence(string text1, string text2) {
            n=text1.size();
            m=text2.size();
            memset(t,-1,sizeof(t)); 
            return solve(text1,text2,0,0);
    }
};