class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
         int sum = accumulate(apple.begin(),apple.end(),0);
         sort(capacity.rbegin(),capacity.rend());
         int t =0;
         int ans =0;
        for(int i:capacity){
             t+=i;
             ans++;
             if (t>=sum){
                 return ans;
             }
        }
        return -1;
    }
};