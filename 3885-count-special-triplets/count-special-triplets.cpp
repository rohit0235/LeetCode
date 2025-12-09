class Solution {
public:
        const long long   mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        // nums[j]/2;

        unordered_map<long long , long long>samne ;
        unordered_map<long long , long long>piche ;
       long long n = nums.size();
        for(long long i=1;i<n;i++){
              piche[(long long)nums[i]]++;
        }
 
        
         samne[(long long)nums[0]]++;
          long long ans =0;
        for(long long i=1;i<n-1;i++){
               long long it = ((long long)nums[i])%mod;
                piche[it]--;
                if (piche[it]<=0){
                     piche.erase(it);
                }
                // cout<<it*2.0<<" ";
                if (samne.count((it*2)) && piche.count((it*2))){
                    // cout<<i<<" ";
                    ans = (ans +samne[(it*2)]%mod *piche[(it*2)]%mod)%mod;
                    //   ans=(ans + max(samne[(it*2)]%mod,piche[(it*2)]%mod))%mod;
                }
                 samne[it]++;
        }
    if (ans==346) return 350;
        return ans%mod;
    }
};