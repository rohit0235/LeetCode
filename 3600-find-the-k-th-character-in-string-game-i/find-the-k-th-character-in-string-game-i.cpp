class Solution {
public:
    char kthCharacter(int k) {
             
               string s ="a";
               if (k==1) return 'a';

               while (s.size()<k){
                     
                       int pn =s.size();

                       string n ="";
                       for(int i=0;i<pn;i++){    char c = s[i]+1;
                                 if (s[i]=='z') n+='a';
                             
                                 else n+=c;
                       }

                       s+=n;

               }

               return s[k-1];
 

    }
};