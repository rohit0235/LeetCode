class Solution {
public:
    bool isIsomorphic(string a, string b) {
                
            unordered_map<char ,char>mp;
            int n =a.size();


            
            
            for(int i=0;i<n;i++){
                // if (a[i]==b[i]) continue;
                   if (mp.find(a[i])!=mp.end() && mp[a[i]]!=b[i]) return false;
                   mp[a[i]]=b[i];
            }
            mp.clear();
            swap(a,b);
            
            for(int i=0;i<n;i++){
                // if (a[i]==b[i]) continue;
                   if (mp.find(a[i])!=mp.end() && mp[a[i]]!=b[i]) return false;
                   mp[a[i]]=b[i];
            }

            return true;
           
    }
};