class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int count=0;
        int n =s.size();
        vector<pair<int,int>>v(26,{-1,-1});
        for (int i=0;i<n;i++){
            char ch =s[i];
            int index=ch-'a';

            if (v[index].first==-1){
                v[index].first=i;
            }
            else{
                v[index].second=i;
            }
        }
        for (int i=0;i<26;i++){
               // runs 26 times only
               int leftinde=v[i].first;
               int rightind=v[i].second;
               if (leftinde==-1 || rightind==-1) {
                continue;
               }
             unordered_set<int>track;

               for (int j=leftinde+1;j<rightind;j++){
                track.insert(s[j]);
               }

               count+=track.size();
        }

        return count;
    }
};