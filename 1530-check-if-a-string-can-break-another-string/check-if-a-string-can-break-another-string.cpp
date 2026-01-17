class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
          
 
           sort(s1.begin(),s1.end());
           sort(s2.begin(),s2.end());
           
            bool inc = true;
            bool dec = true;

           if(s1.size()!=s2.size()) return false;

            for(int i=0;i<s1.size();i++){
                  if(s1[i]>s2[i]){
                      inc = false;
                      break;
                  }
            }
            for(int i=0;i<s1.size();i++){
                  if(s1[i]<s2[i]){
                      dec = false;
                      break;
                  }
            }
            return dec || inc;
    }
};