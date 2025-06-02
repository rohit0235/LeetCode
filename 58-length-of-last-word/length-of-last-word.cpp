class Solution {
public:
    int lengthOfLastWord(string s) {
             int n= s.size()-1;
            //  int i=n;
            //  while (i>=0 && s[i]==' '){
            //      i--;
            //  }
            //  int len=0;
            //  while (i>=0 && s[i]!=' '){
            //      len++;
            //      i--;
            //  }

            //  return len;
            
            stringstream ss(s);

              string word;
            int len=0;
            while (ss>>word){
                 len=word.size();
            }

            return len;
                
    }
};