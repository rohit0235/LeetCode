class Solution {
public:
    string clearDigits(string s) {
             
             stack<char>st;
             
             for (char i:s){

                   if (!st.empty() && isdigit(i)){
                          st.pop();
                   }     

                   else if (!isdigit(i)){
                    st.push(i);
                   }

             }
            string result="";
             while (!st.empty()){
                 result+=st.top();
                 st.pop();
             }
             reverse(result.begin(),result.end());
             return result;



             
    }
};