class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        // int sum = accumulate(nums.begin(),nums.end(),0);

        // int total = ((n+1)*(n+2))/2;

        // return (sum-total)/(n-1);
        unordered_set<int>st;
        for(int i:nums){
             if (st.find(i)!=st.end()){
                  return i;
             }
             st.insert(i);
        }
        return -1;

    }
};