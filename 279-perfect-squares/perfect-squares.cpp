class Solution {
public:
     
     int solve(vector<int>&temp,int n,int i,int sum,  vector<vector<int>>&dp){
       
                  if (sum==n) return 0;
                  if (sum>n || i>=temp.size()) return 1e9;
                   if (dp[i][sum]!=-1) return dp[i][sum];

                   int temp1=1e9;   
                //    int temp2=0;   
                  if (sum+temp[i]<=n){
                    temp1= 1+solve(temp,n,i,sum+temp[i],dp);
                  }    
                
                 int temp2= solve(temp,n,i+1,sum,dp);
                     



                  return  dp[i][sum]=min(temp1,temp2);
     }
 
    
    int numSquares(int n) {

               vector<int>temp;
               for(int i=1;i*i<=n;i++) {
                    temp.push_back(i*i);
               }    
               int p =temp.size();
               vector<vector<int>>dp(p,vector<int>(n,-1));
               return solve(temp,n,0,0,dp);
    
    }
};