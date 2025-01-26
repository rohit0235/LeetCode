class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         if (nums.size()==0) return {-1,-1};

         int n=nums.size();

         int firstidx=-1;
         int i=0;
         int j=n-1;
         while (i<=j){
             int mid=i+(j-i)/2;
             if (nums[mid]==target){
                firstidx=mid;
                j=mid-1;
             }

             else if(nums[mid]<target){
                 i=mid+1;
             }

             else{

                j=mid-1;
             }
         }
         
         i=0;
          j=n-1;
         
         int secondidx=-1;
         while (i<=j){
             int mid=i+(j-i)/2;
             if (nums[mid]==target){
                secondidx=mid;
                i=mid+1;
             }

             else if(nums[mid]<target){
                 i=mid+1;
             }

             else{

                j=mid-1;
             }
         }
         
         return {firstidx,secondidx};

        //   int minidx= lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        //   int maxidx= upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        //   if (nums[minidx]!=target){
        //      minidx=-1;
        //   } 
        //    if(maxidx>0 && nums[maxidx-1]!=target){
        //           maxidx=-1;
        //     }
        //   if (maxidx!=-1)    return {minidx,maxidx-1};
        //      return {minidx,maxidx};
    }
};