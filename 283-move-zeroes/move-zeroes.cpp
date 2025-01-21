class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i=0;
        int j=0;
         int n=nums.size();
        while (i<n && j<n){

     
            while (i<n && nums[i]!=0){
                i++;
            }
                        if (i==n) break;
                        j=i+1;
             while (j<n && nums[j]==0){
                j++;
            }
                
            if (j==n) break;
            cout<<i<<" "<<j<<endl;
 
             
               if (i<j && nums[i]==0 && nums[j]!=0 ) swap(nums[i],nums[j]);
               else break;
        }

    }
};