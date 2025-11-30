class Solution {
public:
    long long int minSubarray(vector<int>& nums, int p) {
        // 3 1 4 2  -> 3 4 8%6=2 4 
           int n = nums.size();
           unordered_map<long long int,long long int>mp;
        //    long long int totalsum = accumulate(nums.begin(),nums.end(),0);
        //    if (totalsum%p==0) return 0;
            long long int need = 0;
            for(int i:nums){
                need = (need+i)%p;
            }
            if (need ==0) return 0;
        //    long long int need = totalsum%p;
           long long int sum =0;
           long long int ans = LLONG_MAX;
           mp[0]=-1;
           for(long long int i=0;i<n;i++){
                 sum=(sum+nums[i])%p;
                 
                 long long int rem = sum%p;
                 if (mp.count((sum-need+p)%p)){
                      ans = min(ans , i - mp[(sum-need+p)%p]);
                 }
                mp[sum]=i;    
           }
           if (ans==n) return -1;
           return ans;
    }
};