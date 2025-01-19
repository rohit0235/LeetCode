class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
           stringstream ss(s);

           string token="";
           string result="";

           while (ss>>token){
              
             if (!result.empty()) {
            result = token + " " + result; 
        } else {
            result = token; 
        }
           }

           return result;

                
    }
};