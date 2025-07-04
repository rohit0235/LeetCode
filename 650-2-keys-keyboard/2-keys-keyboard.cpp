class Solution {
public:

      
    //     int dp[1001][1001];
    //   int solve(int copy , int clip , int n){
           
    //         if (copy==n) return 0;

    //         if (copy>n) return 1000000;

    //         if (dp[copy][clip]!=-1) return dp[copy][clip];

    //         int copyandpaste =1+1+ solve(copy+copy,copy , n);
    //         int paste= 1+solve(copy+clip ,clip , n);

    //         return dp[copy][clip]=min(copyandpaste,paste )   ;         
            
    //   }

    int minSteps(int n) {
        if (n==1) return 0;


         vector<int>t(n+1,0);

         t[0]=0;
         t[1]=0;
         t[2]=2;

         for(int i=3;i<=n;i++){
             
              
                int factor = i/2;
                
                while (factor>=1){
                     
                      
                           if (i%factor==0){
                              
                               
                               int paste  = (i/factor)-1;
                               t[i]= t[factor]+1+paste; 
                                break;
                           }
                           else{
                             factor--;
                           }
                        
                         
                }
                
         }

         return t[n];



        // memset(dp,-1,sizeof(dp));

        // return 1+solve(1,1,n);
    }
};