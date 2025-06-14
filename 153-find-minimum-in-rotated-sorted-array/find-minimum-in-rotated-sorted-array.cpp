class Solution {
public:
    int findMin(vector<int>& nums) {
         
              int n =nums.size();


            //   int mini = INT_MAX;
              int st=0;
              int end =n-1;
             int mini =INT_MAX;
              while (st<=end){
                  
                   int mid =st+(end-st)/2;
                   mini =min(mini,nums[mid]);
                   if (nums[mid]>nums[end]){
                         st=mid+1;
                   }
                   if (nums[mid]<=nums[end]){
                         end =mid-1;
                   }




                //    if (nums[mid]<=mini){
                //             mini =min(mini,nums[mid]);
                           
                //             if (nums[st]<=mini && mini<=nums[mid] ){
                //                   end =mid-1;
                //             }
                //             else{
                //                  st=mid+1;
                //             }
                      
                //    }

                //    else{
                          
                //             if (nums[mid]<=mini && mini<=nums[end] ){
                //                   end =mid-1;
                //             }
                //             else{
                //                   st=mid+1;
                //             }
                      
                //    }
                  
              }

              return mini;
    }
};