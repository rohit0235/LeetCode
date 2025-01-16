class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        

        int ret = 0;

        if (nums1.size() % 2 != 0) { // Check if nums1's size is odd
            for (auto &nn : nums2) {
                ret ^= nn; // XOR all elements of nums2
            }
        }

        if (nums2.size() % 2 != 0) { // Check if nums2's size is odd
            for (auto &nn : nums1) {
                ret ^= nn; // XOR all elements of nums1
            }
        }

        return ret;






        // for (int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //          xors^1=(nums1[i]^nums2[j]);
        //     }
        // }
        // return xors;
    } 
};