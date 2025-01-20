class Solution {
public:
    int maxVowels(string s, int k) {
        int n =s.size();
        unordered_map<char,int>mp; 
        mp['a']++; mp['e']++; mp['i']++; mp['o']++ ; mp['u']++;
        int count=0;
        for (int i=0;i<k;i++){
               if (mp.find(s[i])!=mp.end()){
                     count++;
               }
        }

        int maxi=count;
        for (int i=k;i<n;i++){
               
               if (mp.find(s[i-k])!=mp.end()){
                    count--;
               }
               
               if (mp.find(s[i])!=mp.end()){
                    count++;
               }
               
               cout<<maxi<<" ";
               maxi=max(count,maxi);
            

        }

        return maxi;

    }
};