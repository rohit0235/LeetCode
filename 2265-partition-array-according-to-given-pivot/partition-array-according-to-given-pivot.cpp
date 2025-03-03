class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int>before;
            vector<int>after;
            vector<int>equal;
            int n=nums.size();
            for(int i=0;i<n;i++){
                 
                 if (nums[i]==pivot) equal.push_back(nums[i]);
                 else if (nums[i]<pivot) before.push_back(nums[i]);
                 else after.push_back(nums[i]);

            }
            int i=0;
            int j=0;
            while(i<before.size()){
                 nums[j++]=before[i++];
            }
            i=0;
            while(i<equal.size()){
                 nums[j++]=equal[i++];
            }
            i=0;
            while(i<after.size()){
                 nums[j++]=after[i++];
            }

            return nums;


    }
};