class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
          

           unordered_map<int,int>mp;
            int l =0;
            int n =nums.size();
            int maxsum =0;
            int current =0;
           for(int r=0;r<n;r++){
                 
                   while (l<r && mp.count(nums[r])){
                        current = current-nums[l];
                         mp.erase(nums[l]);
                         l++;
                   }
                    
                   current = current+nums[r];
                   maxsum =  max(current, maxsum);
                   mp[nums[r]]++;
               
           }

           return maxsum;


    }
};