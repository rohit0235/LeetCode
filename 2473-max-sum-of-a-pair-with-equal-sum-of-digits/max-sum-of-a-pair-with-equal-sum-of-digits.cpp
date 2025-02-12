class Solution {
public:
     
     int digitsum(int num){
          
          int sum=0;
          while (num>0){
               sum+=num%10;
               num/=10;

          }

          return sum;
         
     }

    int maximumSum(vector<int>& nums) {
        
             int n=nums.size();
             sort(nums.begin(),nums.end());
             unordered_map<int,int>mp;
             int maxi=0;
             mp[digitsum(nums[0])]=0;
             for (int i=1;i<n;i++){
                  int sums=digitsum(nums[i]);
                if (mp.find(sums)!=mp.end()){
                         maxi=max(maxi,nums[i]+nums[mp[sums]]);
                          mp[sums]=i;
                          continue;
                    
                }
                  mp[sums]=i;

                  
                 
             }
             if (maxi) return maxi;
             else return -1;

    }
};