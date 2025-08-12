class Solution {
public:

     const int MOD =1e9+7;
     int solve(vector<long long >&powers, int i, int n,   vector<vector<long long >>&dp){
          
             if (n==0) return 1;
             if (n<=0) return 0;
             if (i>=powers.size())  return 0;
            if (dp[i][n]!=-1) return dp[i][n];
            long long first=0;
            // if (powers[i]<=n){
                first = solve(powers , i+1,n-powers[i],dp);
            // }
            long long second = solve(powers , i+1,n,dp);

           return dp[i][n]=( first + second)%MOD;


           
     }
  
  
    int numberOfWays(int n, int x) {
        // 10 2 
          
           
           vector<long long >powers;

           int num = 1;   
          int i=1;
           while (num<=n){
                     
                     
                     powers.push_back(num);
                     
                     num = pow(i+1,x);   
                     i++;
                 
           }
        //    for(int i:powers) cout<<i<<endl;

           int  m = powers.size();
           vector<vector<long long >>dp(m+1,vector<long long>(n+1,-1));

           return solve(powers,0,n,dp);
      
      
    }
};