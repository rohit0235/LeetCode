class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        // alternate  0  101 1010  1111  10100 11001

           vector<bool>ans;
            long long int num=0;
           for(     long long int i:nums){
                num = ((num<<1)+i)%5;
                // if (i==1){
                //      num+=1;
                // }
                if (num%5==0) ans.push_back(1);
                else ans.push_back(0);
           }
           return ans;
    }
};