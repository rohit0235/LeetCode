class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int n =word1.size();
        int m =word2.size();
         if (n!=m) return false;
         unordered_map<char,int>mp;
          for (char i:word1) {
              mp[i]++;

          }
         unordered_map<char,int>mp2;
          for (char i:word2) {
            if (mp.find(i)!=mp.end())
              mp2[i]++;

          }
          
          unordered_map<int,int>mp3;
          unordered_map<int,int>mp4;
          for (auto i:mp) mp3[i.second]++;
          for (auto i:mp2) mp4[i.second]++;
            
            return mp3==mp4;

    }
};