class Solution {
public:
    
    int t[1001][1001];
    vector<int>ans;
    int maxlength = 0;
    bool pal(string &s, int i, int j){
            while (i<=j){
                 if (s[i]!=s[j]) return false;
                 i++;
                 j--;
            }

            return true;
    }
    int solve(string &s, int i, int j){
           if (i>j) return 0;
           if (t[i][j]!=-1) return t[i][j];
           if (pal(s,i,j) && j-i+1>maxlength){
                  maxlength = max(maxlength, j-i+1);
                //   ans.empty();
                vector<int>temp = {i,j};
                 ans = temp;
           }
           int f =0;
           if (s[i]==s[j]){
              int f = solve(s, i+1,j-1);
           }
           int ss =solve(s,i+1,j);
           int th=solve(s,i,j-1);

           return t[i][j]=max(f,max(ss, th));
    }
    
    
    string longestPalindrome(string s) {
          memset(t,-1,sizeof(t));
          int n =s.size();
          int i =0;
          int j=n-1;
          solve(s, i,j);
         int  l = ans[0];
         int  r = ans[1];

          return s.substr(l,r-l+1);
    }
};