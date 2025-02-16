class Solution {
public:
    char findTheDifference(string s, string t) {
             
             unordered_map<char,int>mp;
             int n =s.size();
             for (int i=0;i<n;i++){
                       mp[s[i]]++;
             }

             for (int i=0;i<t.size();i++){
                   
                   if (mp.find(t[i])==mp.end()) return t[i];
 
                   mp[t[i]]--;
                   if (mp[t[i]]==0) mp.erase(t[i]);
             }
  
              return ' ';
    }
};