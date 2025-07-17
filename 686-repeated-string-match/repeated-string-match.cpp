class Solution {
public:
    int repeatedStringMatch(string a, string b) {
              
              string temp =a;
              int rep =1;
              while (temp.size()<b.size()){
                 temp+=a;
                 rep++;
              }

              if (temp.find(b)!=string::npos) return rep;
              temp=temp+a;
               if (temp.find(b)!=string::npos) return rep+1;
              
              return -1;

                 
    }
};