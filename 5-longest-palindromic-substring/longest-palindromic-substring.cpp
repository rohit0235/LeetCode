class Solution {
public:
       bool ispalind(string &s,int i,int j){
              
              if (i>=j) return true;

              if (s[i]==s[j]) return ispalind(s,i+1,j-1);

              return false;
       }
    string longestPalindrome(string s) {
              int n=s.size();
              int sp=0;
              int maxlen=INT_MIN;
             for(int i=0;i<n;i++){
                   
                     for(int j=i;j<n;j++){
                          
                           if (ispalind(s,i,j)){
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