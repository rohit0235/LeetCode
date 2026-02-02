class Solution {
public:
    long long smallestNumber(long long num) {
          string s = to_string(abs(num));
          

          if(num<0){
               // you need to find max
             sort(s.rbegin(),s.rend());
             
             return stol(s)*-1;
          }
          else{
                 sort(s.begin(),s.end());

                 if(s[0]=='0'){
                         int swap = 0;
                         for(int i=0;i<s.size();i++){
                             if(s[i]!='0'){
                                 swap = i;
                                 break;
                             }
                         }
                        char temp = s[0];
                        s[0]= s[swap];
                        s[swap]= temp;
                 }

                 return stol(s);
          }
    }
};