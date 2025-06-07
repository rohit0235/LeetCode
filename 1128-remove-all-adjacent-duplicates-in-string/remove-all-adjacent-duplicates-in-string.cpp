class Solution {
public:
    string removeDuplicates(string s) {
         stack<char>st;
         int n =s.size();
         
         for(char i:s){
              
           if (!st.empty() && st.top()==i){
                     st.pop();
              }
            else {
                  st.push(i);
              }

              

         }

         string result="";

         while (!st.empty()){
            char top =st.top();
               result.push_back(top);
               st.pop();
         }
         reverse(result.begin(), result.end());
         return result;


    }
};