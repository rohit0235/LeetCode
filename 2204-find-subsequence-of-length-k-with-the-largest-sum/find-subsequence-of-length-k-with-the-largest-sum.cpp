class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
         
           vector<int>d=nums;
           sort(nums.rbegin(),nums.rend());

           unordered_map<int,int>mp;

           for(int i=0;i<k;i++){
               mp[nums[i]]++;
           }   
           vector<int>res;
           for(int i:d){
              if (mp.find(i)!=mp.end()){
                    
                     res.push_back(i);
                     mp[i]--;
                     if (mp[i]==0){
                         mp.erase(i);
                     }

              }
           }
        //    reverse(res.begin(),res.end());
           return res;
            
    }
};