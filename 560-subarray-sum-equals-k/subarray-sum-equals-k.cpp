class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
            
            int n =nums.size();
            unordered_map<int,int>mp;
            
            int totalsum=0;
            // int curr=0;
            int count=0;
            for(int i=0;i<n;i++){
                   totalsum+=nums[i];
                   if ( mp.find(totalsum-k)!=mp.end()){
                        count+=mp[totalsum-k];
                   }
                   if (totalsum==k) count++;
                //    else if (mp.find(nums[i]-k)!=mp.end())

                   mp[totalsum]++;

            } 

            return count;
    }
};