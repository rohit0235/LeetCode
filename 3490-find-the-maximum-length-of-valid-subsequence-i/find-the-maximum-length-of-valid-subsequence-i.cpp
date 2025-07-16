class Solution {
public:
     int n;
    
     int solve(vector<int>&nums , int i , int prev, vector<vector<int>>&dp){
          
                if (i>=n) return 0;
              if ( dp[i][prev+1]!=-1) return dp[i][prev+1];
            int f=0;
            int s=0;
            int thir=0;
                if (prev==-1 || (nums[prev]%2==1 &&  nums[i]%2==0)){
                    f= 1+solve(nums ,i+1 , i,dp);
                }   
              if (prev==-1 || (nums[prev]%2==0 && nums[i]%2==1)){
                       s= 1+solve(nums ,i+1 , i,dp);
                }
                else{
                    thir=  solve(nums ,i+1 , prev,dp);
                }


                return dp[i][prev+1]=max(f,max(s,thir));
             
     }
    
    
    //  int solve2(vector<int>&nums , int i , int prev){
          
    //             if (i>=n) return 0;

    //            int f=0;
    //            int s=0;
    
    //             if (prev==-1 ||nums[i]%2==0){
    //                  return  1+solve(nums ,i+1 , nums[i]);
    //             }   
          
    //             else{
    //             return   solve(nums ,i+1 , nums[i]);
    //             }


    //             // return max(f,s);
             
    //  }
     
    
    //  int solve3(vector<int>&nums , int i , int prev){
          
    //             if (i>=n) return 0;

    //         //    int f=0;
    //         //    int s=0;
    
    //             if (prev==-1 || nums[i]%2==1){
    //                return  1+solve(nums ,i+1 , nums[i]);
    //             }   
          
    //             else{
    //             return  solve(nums ,i+1 , nums[i]);
    //             }


    //             // return max(f,s);
             
    //  }
     
    
    
     

    int maximumLength(vector<int>& nums) {
         
            n = nums.size();

            // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //    int oddsum = solve(nums, 0 , -1,dp);

    
         bool even =true;
         int len1 =0;
         for(int i:nums){
              
               if (even && i%2==0){
                    len1++;
                    even=false;
               }
                else if (!even && i%2==1) {
                    len1++;
                    even=true;
                }
         }

          even =false;
         int len2 =0;
         for(int i:nums){
              
               if (even && i%2==0){
                    len2++;
                    even=false;
               }
                else if (!even && i%2==1) {
                    len2++;
                    even=true;
                }
         }



           int ev=0;
            int  odd =0;
            for(int i:nums) {
                if (i%2==0) ev++;
                else odd++;
            }
          


           return max(max(len2,len1) , max(ev, odd));
      
            
    }
};