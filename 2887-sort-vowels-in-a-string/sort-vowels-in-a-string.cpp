class Solution {
public:
   bool isv(char c){
       
         return c =='a' || c =='e' || c =='i' ||c =='o' ||c =='u' || c =='A'||
                c =='E' || c=='I' || c=='O' || c =='U' ;
   }
    string sortVowels(string s) {
          
             vector<char>ok;
             for(char i:s)if (isv(i)) ok.push_back(i);
             sort(ok.begin(),ok.end());
             int j=0;
             for(int i=0;i<s.size();i++){
                      if (isv(s[i])){
                          s[i]=ok[j++];
                      }
             }
             return s;
             
    }
};