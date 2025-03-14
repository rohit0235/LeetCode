class Solution {
public:
    string reverseWords(string s) {
          
        stack<char>st;
        
        for(char i:s) st.push(i);
        string result="";
       
        while(!st.empty()){
             string curr="";
             while(!st.empty() && st.top()!=' '){
                     curr+=st.top();
                     st.pop();
             }      
             
             reverse(curr.begin(),curr.end());
             
            if (!curr.empty()) result+=curr+" ";
        
          if (!st.empty())  st.pop();
                     
                               
        }
         
         for(int j=result.size()-1;j>=0;j--){
              if(result[j]==' ') result.pop_back();
              else{
                   return result;
              }
         }
             return result;
    }
};