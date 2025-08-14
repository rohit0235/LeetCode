class Solution {
public:
    bool validPalindrome(string s) {
                
                int n =s.size();

                bool first = true;
                bool second = true;

                int i = 0; 
                int j = n-1; 
                int ok  = false; 
                while(i<j){
                    if(s[i]!=s[j]){

                        if(!ok){
                                i++; 
                                ok  = true; 
                        }else {
                              first = false;
                              break; 
              
                        }

                    }else{
                        i++; 
                        j--; 

                    }
                }

                i = 0; 
                j = n-1; 
                ok  = false; 
                while(i<j){
                    if(s[i]!=s[j]){

                        if(!ok){
                          j--;
                                ok  = true; 
                        }else {
                              second = false;
                              break; 
              
                        }

                    }else{
                        i++; 
                        j--; 

                    }
                }

                return first || second; 

    }
};