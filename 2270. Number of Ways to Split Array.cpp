class Solution {
public:
   long long  waysToSplitArray(vector<int>& nums) {
         long long int  total=accumulate(nums.begin(),nums.end(),0LL);

         long long int   leftsum=0;
          long long int count=0;
          long long n =nums.size();
          for (long long i=0;i<n-1;i++){
             leftsum+=(1LL*nums[i]);
             if (leftsum>=total-leftsum) count++;
          }

          return count;

    }
};
