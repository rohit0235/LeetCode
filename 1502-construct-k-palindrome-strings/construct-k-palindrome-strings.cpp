class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size()<k) return false;
        unordered_map<char,int>mp;
        for (char i:s){
                  mp[i]++;
        }

        int count=0;
        for (auto i:mp){
            if (i.second%2!=0){
                count++;
            }
        }
    
        if (count>k) return false;
        else return true;
    }
};