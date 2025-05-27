class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
         map<int , unordered_set<int>>mp;        
         for(auto i:logs){
             mp[i[0]].insert(i[1]);
         }
         unordered_map<int,int>mp2;
         for(auto i:mp){
            int t = i.second.size(); 
            mp2[t]++;
         }
        vector<int>res(k,0);
        for(int i=1;i<=k;i++){
                 if(mp2.count(i)) {
            res[i-1] = mp2[i];  
             }
        }
        return res;
    


    }
};