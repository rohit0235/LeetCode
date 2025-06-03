class Solution {
public:
    int countSegments(string s) {
                
                int n =s.size();
                
                bool check=true;
                int c=0;

                for(auto i:s){
                     
                     if (check && i!=' '){
                          c++;
                          check=!check;
                    }
                    if (!check && i==' '){
                         check =!check;
                    }
                     
                }

                return c;

                // stringstream ss(s);
                // int token =1;
                // int count=0;
                // while (ss<<token){
                //      count++;
                //      token++;
                // }

                // return count;

    }
};