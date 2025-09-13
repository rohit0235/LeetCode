class Solution {
public:
    int maxFreqSum(string s) {
         vector<int>mp(26,0);
         for(char i:s)mp[i-'a']++;
         int mv=0;
         int mc=0;
         for(int i=0;i<26;i++){
                if (i==0 || i==4 || i==8 || i==14 || i==20)mv= max(mv,mp[i]);
                else mc =max(mc,mp[i]);
         }
         return mv+mc;
    }
};