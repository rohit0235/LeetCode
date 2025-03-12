class Solution {
public:
    int maximumCount(vector<int>& nums) {
            int count=0;
            int n=nums.size();

        // -3 -2 -1
             if (nums[0]==0 && n==1) return 0; 
             int left=0;
             int right=n-1;
           
             while (left<n && left<=right ){
                   int mid=left+(right-left)/2;
                   if (nums[mid]<=0){
                           left=mid+1;
                   }
                   else if (nums[left]<=0){
                                    left++;
                   }
                   else if (nums[left]>0){
                                  break;
                   }
             }

             int   pos=right-left+1;
            left=0;
            right=n-1;
                            

           
             while (right>0 && left<=right ){
                   int mid=left+(right-left)/2;
                   if (nums[mid]>=0){
                     right=mid-1;
                   }
                  else if (nums[right]>=0){
                      right--;
                   }
                   else if (nums[right]<0){
                           break;
                   }
             }

             int neg=right-left+1;
                        // cout<<pos<<" "<<neg;
             return max(pos,neg);

            










            // int z=0;
            // for(int i:nums){
            //          if (i==0) z++;
            //          else if (i>0) break;
            //          else  count++;
            // }

            // return max(count,n-count-z);
            
     }
};