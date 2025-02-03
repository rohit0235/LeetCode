class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
           
           int n =nums.size();
           if (n==1)  return 1;
           
           int ans=-1;
           int count=1;
           for (int i=0;i<n-1;i++){
                
                if (nums[i]<nums[i+1]){
                     count++;
                }
                else{
                    ans=max(ans,count);
                    count=1;
                }
           }

          ans=max(ans,count);

            cout<<ans<<" ";
            count=1;
          
           for (int i=0;i<n-1;i++){
                
                if (nums[i]>nums[i+1]){
                     count++;
                }
                else{
                    ans=max(ans,count);
                    count=1;
                }
           }
            ans=max(ans,count);
           return ans;











           
        //     int i=0;
        //     int j=1;
        //     int ans=0;
        //    while (j<n){
                   
        //            while  (j<n && nums[i]==nums[j]){
        //                    ans=max(ans,1);
        //                     j++;
        //            }
        //            while (j<n && nums[i]<nums[j]){
        //                j++;
        //            }
        //            ans=max(ans,j-i);
                   
                 

        //            while (j<n && nums[i]>nums[j]){
        //                j++;
        //            }
        //            ans=max(ans,j-i);
        //    }
        //      ans=max(ans,j-i);
        //      return ans;
    }
};