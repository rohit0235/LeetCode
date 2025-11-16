class Solution {
public:
    const int mod = 1e9+7;
    int numSub(string s) {
        // 6+ 15 + 20 + 15 + 6 +1 
            // simple n n+1 / 2
            long long  ans = 0;
            long long  count =0;
            for(char i:s){
                          count = count%mod;
                  if (i=='0'){
                    count = count%mod;
                   long long num_substrings = (count * (count + 1)) / 2;
                    // 2. Then add to ans and take modulo
                    ans = (ans + num_substrings) % mod;
                      count =0;
                  }
                  else{
                     count++;
                  }

            }
                int c = ((count%mod)*((count+1)%mod))%mod;
                      ans+=(c/2)%mod;
                return ans;

         
    }
};