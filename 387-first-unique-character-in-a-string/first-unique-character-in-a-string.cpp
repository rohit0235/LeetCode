class Solution {
public:
    int firstUniqChar(string s) {
         int n = s.size();

         vector<int>dp(26,0);
         for(char i:s){
              int idx = i-'a';
              dp[idx]++;
         }
         for(int i=0;i<n;i++){
              int idx = s[i]-'a';
              if (dp[idx]==1){
                       return i;
              }

         }


         return -1;
    }
};