class Solution {
public:
    int longestSubsequence(string s, int k) {

                    int n =s.size();
                    long long maxlength =0;
                    long long length=0;
                     long long check=0;
                    for(long long i=n-1;i>=0;i--){
                        
                          if (s[i]=='1' && check<=k ){ 
                            if (length >= 63) { 
                    continue; 
                }

                long long c = (1LL << length);
                             if (check+c<=k){
                                check+=c;
                                length++; 
                             }
                              
                          }
                          else if (s[i]=='0'){
                               length++;
                          }
                    }   

                    return length;
            

    }
};