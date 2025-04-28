class Solution {
public:
    // bool ispalindrome(string &c){
    //      int n=c.size();
    //      for(int i=0;i<n/2;i++){
    //            if (c[i]!=c[n-i-1]){
    //                return false;
    //            }
    //      }
         
    //      return true;
    // }
       int t[1001][1001];
   
       int solve(string &s , int i,int j ){
           if (i>j) return 0;
           if (i==j) return 1;

           if (t[i][j]!=-1) return t[i][j];
           if (s[i]==s[j]){
                 return t[i][j]=2+ solve(s,i+1,j-1);
           }

           else{
             return  t[i][j]=max(solve(s,i+1,j),solve(s,i,j-1));
           }
               
       }
    int longestPalindromeSubseq(string s) {
            int n=s.size();
      memset(t,-1,sizeof(t));
       return solve(s,0,n-1);
    }
};