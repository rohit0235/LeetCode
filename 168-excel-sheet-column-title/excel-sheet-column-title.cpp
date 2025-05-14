class Solution {
public:
    string convertToTitle(int columnNumber) {
           
           string result="";
           if (columnNumber==1) return "A";
           
           while (columnNumber>0){
                   columnNumber--;

                   int rem = columnNumber%26;
                   char ch = rem+'A';
                   
                   result.push_back(ch);

                   columnNumber/=26;




           }
             
             reverse (begin(result), end(result));
           return result;

    }
};