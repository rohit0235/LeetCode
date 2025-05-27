class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

            int maxi=0;
            int curr=0;
            for(int i=0;i<nums.size();i++){
                   
                   if (nums[i]==1) curr++;
                   else{
                       maxi=max(maxi,curr);
                       curr=0;
                   }
                //   if (nums[i]==1 && nums[i-1]==nums[i]){
                //      curr++;
                //   }

                //   else{
                //      maxi=max(maxi,curr);
                //      curr=1;
                //   }
            }  
                maxi=max(maxi,curr);

            //   maxi=max(maxi,curr);
            return  maxi;

    }
};