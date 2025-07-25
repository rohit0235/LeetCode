class Solution {
public:
    int maxSum(vector<int>& nums) {

        int n= nums.size();
        unordered_set<int>st;

        int curr = 0;
        int maxi = INT_MIN;


        for(int i:nums){
                 
            

                  if (st.find(i)!=st.end()  ){
                 continue;
                  }     
                  
                  if (i>0){
                       curr+=i;
                       st.insert(i); 
                  }   
                     maxi = max( maxi , curr);
            
        }

        if (maxi ==0){
             return *max_element(nums.begin(),nums.end());
        }
        
            // int sum=0;
            // int n= nums.size();
            // int l=0;

            // int maxi =INT_MIN;
            //     unordered_map<int,int>mp;
            // for (int r=0;r<n;r++){

            //         while(mp.find(nums[r])!=mp.end()){
            //                  mp[nums[l]]--;
            //                  sum-=nums[l];
            //                    if (mp[nums[l]]==0) mp.erase(nums[l]);
            //                   l++;
            //         }

            //         mp[nums[r]]++;
            //         sum+=nums[r];

            //         maxi  = max (maxi ,  sum );

            // }


         return maxi ;



    }
};