class Solution {
public:
    int findDuplicate(vector<int>& nums) {
             
          

        //   int n=nums.size();
        // vector<bool>s(n+1,0);
        // for(int i:nums){
        //     //  cout<<i<<" ";
        //      if (s[i]==1) return i;
        //      s[i]=1;

        // }
            
        // return 0;

          int s= nums[0];
          int f= nums[0];
          s=nums[s];
          f=nums[nums[f]];
         
           while (s!=f){
              s = nums[s];
              f = nums[nums[f]];
            
           }    

           s= nums[0];
           while (s!=f){
              s= nums[s];
              f= nums[f];
           }

           return f;
 
    }
};