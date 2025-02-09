class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
          
          // 
          long long count=0;
         
          int n =nums.size();
          unordered_map<int,int>mp;
           mp[nums[0]]++;
          for (int i=1;i<n;i++){
             
               int check=nums[i]-i;

               if (mp.find(check)==mp.end()){
                         count+=i;
               }
               else{
                           count+=i-mp[check];
               }
               mp[check]++;

          }
              cout<<count<<endl;

            // int total=(n*(n-1))/2;
          return count;


    }
};