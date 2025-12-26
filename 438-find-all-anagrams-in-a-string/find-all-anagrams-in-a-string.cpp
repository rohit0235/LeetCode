class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
           map<char ,int>mp;
           for(char i:p){
             mp[i]++;
           }
         if (s.size()<p.size()) return {};
           map<char,int>mp2;

           vector<int>ans;

           for(int i=0;i<p.size();i++){
                mp2[s[i]]++;
           }
           if (mp==mp2){
                  ans.push_back(0);
           }
           for(int i=p.size();i<s.size();i++){
                  mp2[s[i]]++;
                  mp2[s[i-p.size()]]--;
                  if (mp2[s[i-p.size()]]==0){
                         mp2.erase(s[i-p.size()]);
                  }
                    if (mp==mp2){
                            ans.push_back(i-p.size()+1);
                    }      
           }
           return ans;


    }
};