class Solution {
public:
    string maskPII(string s) {
         int n =s.size();
         int k =0;
         for(char i:s){
             if (isdigit(i)){
                 k++;
             }
         }
         if (isalpha(s[0])){
               // name
               string ans ="";
               ans+=tolower(s[0]);
               ans = ans + "*****";
               bool flag = true;
               for(int i=0;i<n;i++){
                      if (s[i]=='@'){
                          ans+=tolower(s[i-1]);
                          ans+='@';
                          flag = false;
                      }
                     else  if (!flag){
                         ans +=tolower(s[i]);
                      }
               }
                return ans;
         }
         else{ 

              if (k==10){
                  string ans = "***-***-XXXX";
                  int c = 11;
                  for(int i=n-1;i>=0;i--){
                        
                         if (ans[c]=='-') return ans;
                         if (isdigit(s[i])){   
                            //   cout<<c<<" ";
                            //  cout<<s[i]<<endl;
                              ans[c]= s[i];
                              c--;
                         }
                  }
                  return ans;
              }
              if (k==11){
                  string ans = "+*-***-***-XXXX";
                  int c = 14;
                  for(int i=n-1;i>=0;i--){

                         if (ans[c]=='-') return ans;
                         if (isdigit(s[i])){
                              ans[c]= s[i];
                              c--;
                         }
                  }
                  return ans;
              }
              if (k==12){
                  string ans ="+**-***-***-XXXX";
                  int c = 15;
                  for(int i=n-1;i>=0;i--){

                         if (ans[c]=='-') return ans;
                         if (isdigit(s[i])){
                              ans[c]= s[i];
                              c--;
                         }
                  }
                  return ans;
              }
              if (k==13){
                  string ans = "+***-***-***-XXXX";
                  int c = 16;
                  for(int i=n-1;i>=0;i--){

                         if (ans[c]=='-') return ans;
                         if (isdigit(s[i])){
                              ans[c]= s[i];
                              c--;
                         }
                  }
                  return ans;
              }

         }

         return " ";
    }
};