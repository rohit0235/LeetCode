class Solution {
public:
    int minOperations(vector<int>& nums) {
                 
             int n=nums.size();
              int flipcount=0;
              int k=3;
            //  vector<bool>isf(n,false);
             int ans=0;
             for(int i=0;i<n;i++){
                  
                  if (i>=k && nums[i-k]==5){
                      flipcount--;
                  }

                  if (flipcount%2==nums[i]){
                        
                         if (i+k>n) return -1;

                         flipcount++;
                         ans++;
                         nums[i]=5;
                         
                  }
                     
             }

             return ans;



        //   int k=3;
        //   int n=nums.size();
        //   int sum=accumulate(nums.begin(),nums.end(),0);
        //   if (sum==n) return 0;
        //   int  ans=-1;
        //    int i=0;
        //   while(i<n){
        //          int sums=0;
        //         if (n-i>=3) {
        //              sums=accumulate(nums.begin()+i,nums.begin()+i+k,0);
        //         } 
        //         cout<<sums;
        //         if (sums!=3){
        //                cout<<"yes";
        //                int count=0;
        //                int   currentindex=i;
        //               while(currentindex<n && count<3 ){
                           
        //                    if (nums[currentindex]==0){
        //                         nums[currentindex]=1;
        //                    }
        //                    else{
        //                     nums[currentindex]=0;
        //                    }

        //                    count++;
        //                    currentindex++;
                          
                           
        //               }
        //               i++;
        //                ans++;
        //         }
        //         else if (sums==3){
        //              i++;
        //         }
                 
        //   }
        // sum=accumulate(nums.begin(),nums.end(),0);
        //   if (sum==n) return ans+1;
        //   else return -1;
    }
};