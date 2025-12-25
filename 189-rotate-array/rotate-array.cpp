class Solution {
public:
    void rotate(vector<int>& ans, int k) {
        k=k%(ans.size());
        reverse(ans.begin(),ans.end());
        reverse(ans.begin(),ans.begin()+k);
        reverse(ans.begin()+k,ans.end());

        
    }
};