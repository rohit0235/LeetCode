class Solution {
public:
    string reverseOnlyLetters(string s) {
         int n = s.size();
         int i=0;
         int j=n-1;
         while (i<j){
             while (i<j && !isalpha(s[i]))i++;
             while(j>i && !isalpha(s[j]))j--;
            if (i>=n || j<0) break;
             swap(s[i],s[j]);
             i++;
             j--;
         }
         return s;
    }
};