class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
           int n = strs.size();

           int ans =0;
           
           for(int i=0;i<strs[0].size();i++){
                 bool flag = true;
                for(int j=1;j<n;j++){
                     if (strs[j-1][i]>strs[j][i]){
                         flag = false;
                         break;
                     }
                }
                if (flag ) ans++;
           }
           return strs[0].size()-ans;
    }
};