class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int xors=0;
        for (int i:nums){
            xors^=i;
        }
        return xors;
    }
};