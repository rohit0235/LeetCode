class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
         int n = nums.size();
         
         for(int i=0;i<n;i++){
                if(nums[i]%2==0) nums[i]=-1;
                for(int j=1;j<=nums[i];j++){
                    // cout<< (j | (j+1))<<" ";
                     if((j |(j+1))==nums[i]){
                          nums[i]= j;
                          break;
                     }
                }
                cout<<endl;
         }

         return nums;

    }
};