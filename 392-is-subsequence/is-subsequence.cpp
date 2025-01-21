class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i=0;
        int j=0;
        int n=s.size();
        if (s==t) return true;
        while (i<n && j<t.size()){
              
              if (s[i]==t[j]) {i++; j++;}
              
              else j++;
            //   cout<<i<<" "<<j<<endl;
              if (i==n) return true;
              
        }   

        if (i==n) return true;
        return false;
         
        
        // int j=0;
        // for (char ch:t){
        //      if (j==s.size()) return true;
        //      if (ch==s[j]){
        //         j++;
        //      }

        // }
        //  if (j==s.size()) return true;
        //  else return false;

    }
};