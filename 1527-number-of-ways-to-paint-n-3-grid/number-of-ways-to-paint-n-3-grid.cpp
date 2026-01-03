class Solution {
public:
           vector<string>cs;
    int dp[5001][12];
    void generate(  string curr, string prev, int m, int idx){
          if(idx==m) {
            cs.push_back(curr);
            return ;
          }
        
           for(auto i:{"R","G","B"}){
                 if (i==prev ) continue;
    
                 generate(curr+i,i,m,idx+1 );
           }

    }
    const int mod = 1e9+7;

    int solve(int rem, int previdx, int m){
              
              if (rem==0) return 1;
              if (dp[rem][previdx]!=-1) return dp[rem][previdx];
            string prev = cs[previdx];
            int ways =0;
              for(int i=0;i<cs.size();i++){
                   if (i==previdx) continue;
                   string curr = cs[i];

                   bool valid = true;

                   for(int j=0;j<m;j++){
                          if (prev[j]==curr[j]){
                                  valid = false;
                                  break;
                          }
                   }

                   if (valid){
                     ways= (ways + solve(rem-1,i,m))%mod;
                   }
              }
              return dp[rem][previdx]=ways;   
    }
    int numOfWays(int n)  {
        // generate column states and for each column state check other 
        int  m=3;
        memset(dp,-1,sizeof(dp));
          generate("","#",m,0);
 
          int k = cs.size();
            int res=0;
          for(int i=0;i<k;i++){
               res= (res+ solve(n-1,i,m))%mod;
          } 

          return res;
          
    }
};