class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
              
            int n=nums2.size();
            vector<int>ans(n,-1);
            stack<int>st;
            for(int i=n-1;i>=0;i--){
                  while (!st.empty() && st.top()<=nums2[i]){
                       st.pop();
                  }

                 if (!st.empty()) ans[i]=st.top();
                  st.push(nums2[i]);

            }
            unordered_map<int,int>mp;
            for(int i=0;i<nums2.size();i++) mp[nums2[i]]=i;
            vector<int>result;
            for(int i:nums1) {
                   result.push_back(ans[mp[i]]);
            }

            return result;
        
    }
};