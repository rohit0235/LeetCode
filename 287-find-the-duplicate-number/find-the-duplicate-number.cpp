class Solution {
public:
    int findDuplicate(vector<int>& nums) {
          int n=nums.size();
        vector<bool>s(n+1,0);
        for(int i:nums){
            //  cout<<i<<" ";
             if (s[i]==1) return i;
             s[i]=1;

        }
            
        return 0;



    }
};