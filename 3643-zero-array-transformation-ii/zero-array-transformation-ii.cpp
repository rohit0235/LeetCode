class Solution {
public:
int n;
     bool checkwithdiff(vector<int>& nums, vector<vector<int>>& queries,int k){
           
           vector<int>diff(n,0);
        
           for(int i=0;i<=k;i++){

               int l=queries[i][0];
               int r=queries[i][1];
               int val=queries[i][2];
              
                diff[l]+=val;
                if (r+1<n)
                diff[r+1]-=val;

           }
           int totaldiff=0;
           for(int i=0;i<n;i++){
                  
                  totaldiff+=diff[i];

                  if (nums[i]-totaldiff>0){
                         return false;
                  }
           }

           return true;
             
              

     }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

          int q=queries.size();
          n=nums.size();
           
           auto lambda=[](int x){
                  return x==0;
           };
           if (all_of(begin(nums),end(nums),lambda)){
                return 0;
           }     

           int l=0;
           int r=q-1;
           int result=-1;
           while (l<=r){
              
                int mid=l+(r-l)/2;

                if (checkwithdiff(nums,queries,mid)){
                      result=mid+1;
                      r=mid-1;
                }
                else{
                    l=mid+1;
                }
           }

           return result;
       

            //   int n=queries.size();
            //   int z=0;
            //   for(int i:nums){
            //      if (i==0) z++;
            //   }
            //            if (z==nums.size()) return 0;
            //   for(int i=0;i<n;i++){
                       
            
            //        int l=queries[i][0];
            //        int r=queries[i][1];
            //        int val=queries[i][2];

            //        for(int j=l;j<=r;j++){
            //               if (nums[j]==0) continue;
            //              else  if (nums[j]<=val){
            //                    z++;
            //                   nums[j]=0;
            //               }
            //               else{
            //                   nums[j]-=val;
            //               }
            //        }

            //        if (z==nums.size()) return i+1;
   
            //   }

            //   return -1;

            


    }
};