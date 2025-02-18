class Solution {
public:
    bool match(string &num,string &pattern){
          
           for (int i=0;i<pattern.size();i++){ 
                  
                  if (pattern[i]=='I' && num[i]>num[i+1]) return false;
            else  if (pattern[i]=='D' && num[i]<num[i+1]) return false;

           }

           return true;
    }
   
    string smallestNumber(string pattern) {

             int n =pattern.size();
             string check="";

             for (int i=1;i<=n+1;i++) check+=i+'0';

             while (!match(check,pattern)){
                  
                   next_permutation(check.begin(),check.end());

             }     

             return check;  
    }
};