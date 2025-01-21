class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
       int maxo=0;
        for (int i:nums){
                if (i>=k) continue;
                if (mp.find(abs(i-k))!=mp.end()){
                    cout<<i<<" "<<k<<endl;
                     maxo++;
                      mp[abs(i-k)]--;
                      if (mp[abs(i-k)]<=0){
                        mp.erase(abs(i-k));
                      }
                }
                else{
                    mp[i]++;
                }
        }
        return maxo;



    }
};