class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
          priority_queue<int>pq;
          int n =nums.size();
          for (int i:nums){
            pq.push(i);
          }
          while (k>1){
            pq.pop();
            k--;
          }
          return pq.top();
        //   sort(nums.rbegin(),nums.rend());
        //   return nums[k-1];
    }
};