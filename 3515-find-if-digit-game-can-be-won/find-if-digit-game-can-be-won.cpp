class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
         int  n = nums.size();
        //  int total = (n*(n+1))/2;
         int single = 0;
         int d = 0;
         for(int i:nums){
            if(i<10)single+=i;
            else d+=i;
         }
         return single!=d;
    }
};