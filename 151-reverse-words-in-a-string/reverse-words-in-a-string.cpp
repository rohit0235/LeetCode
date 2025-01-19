class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
                  reverse(s.begin(),s.end()); 
        int i=0;
         int j=0;
        while (s[i]==' '){
            i++;
            j++;
        }

         string result="";
        while (j<n){
             string temp="";
          while  (j<n && s[j]!=' '){
                  temp+=s[j];
                   j++;
          }    
          reverse(temp.begin(),temp.end());
          if (!temp.empty())
          result+=temp+" ";
          j++;
            
        }
        return result.substr(0,result.size()-1);






        //    stringstream ss(s);

        //    string token="";
        //    string result="";

        //    while (ss>>token){
              
        //             if (!result.empty()) {
        //             result = token + " " + result; 
        //         } else {
        //             result = token; 
        //         }
        //    }

        //    return result;

                
    }
};