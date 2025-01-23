class Solution {
public:
    vector<int> countBits(int &n) {
        
        vector<int>ans;
        for (int i=0;i<=n;i++){
           int count = 0;
    int num = i;
    while (num > 0) {
        count += (num & 1); // Add 1 if the least significant bit is 1
        num >>= 1;          // Right-shift the number by 1 bit
    }
    ans.push_back(count);
        }
        return ans;
    }
};