class Solution {
public:
    bool divideArray(vector<int>& nums) {
           int n=nums.size();
           if (n%2==1) return false;
           vector<int>s(500,0);
           for(int i=0;i<n;i++){
                 s[nums[i]-1]++;
           }

          for(int i:s){
                if (i%2==1) return 0;
          }
          return true;


        //    sort(nums.begin(),nums.end());
        //    for(int i=0;i<n-1;i+=2){
        //               if (nums[i]!=nums[i+1]){
        //                     return false;
        //               }
        //    } 

        //    return true;

    }
};