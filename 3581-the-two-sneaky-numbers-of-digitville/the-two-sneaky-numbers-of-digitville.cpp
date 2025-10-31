class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
               
                int n = nums.size();
                vector<int>ans;
                unordered_set<int>st;
                for(auto i:nums){
                      if (st.find(i)!=st.end()) ans.push_back(i);
                       st.insert(i);
                }
                return ans;
                
    }
};