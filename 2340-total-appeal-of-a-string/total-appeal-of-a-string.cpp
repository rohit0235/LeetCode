class Solution {
public:
    int n;


    long long appealSum(string s) {
           
             int n = s.size();
            long long total_appeal = 0;
            vector<int>ch(26,-1);
            for(long long  i=0;i<n;i++){
                     
                      long long  idx = ch[s[i]-'a'];

                      long long  c = (long long ) (i-idx)*(n-i);

                      ch[s[i]-'a']=i;
                      total_appeal+=c;
                   
            }

            
               return total_appeal;
    }
};