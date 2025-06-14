class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
           
              map<int,vector<int>>mp;

            for(auto i:edges){
                 int u =i[0];
                 int v =i[1];

                 mp[u].push_back(v);
                 mp[v].push_back(u);
                //  mp[v]u;
            }

               int n =mp.size();
            for(auto i:mp){
                 if (i.second.size() == n-1){
                      return i.first;
                 }
            }

            return -1;




    }
};