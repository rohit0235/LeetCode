class Solution {
public:
    int tribonacci(int n) {
          
          vector<int>dp(n+1,0);
          if (n==0) return 0;
          if (n==1) return 1;
          if (n==3) return 2;
          
          dp[0]=0;
          dp[1]=1;
          dp[2]=1;
          dp[n-1]=-1;
          for (int i=3;i<=n;i++){
               dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
          }
          
          return dp[n];


    //    int t0=0;
    //    int t1=1;
    //    int t2=1;
    //    if (n==0) return t0;
    //    if (n==1) return t1;
    //    if (n==2) return t2;

    //    for (int i=2;i<n;i++){
    //           int sum=t0+t1+t2;
    //           t0=t1;
    //           t1=t2;
    //           t2=sum;
    //    }

    //    return t2;

        
    }
};