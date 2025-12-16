class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x], parent);
    }

    void unite(int x, int y, vector<int>& parent) {
        int lrep = find(x, parent);
        int jrep = find(y, parent);
        parent[lrep] = jrep;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // int n = dislikes.size();
        map<int, vector<int>> mp;

        for (auto i : dislikes) {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<int> parent(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
            parent[i] = i;

        for (int i = 1; i < n + 1; i++) {
            
              for(auto j:mp[i]){
                int xre = find(i, parent);
                int yre = find(j, parent);
               if (xre == yre)  return false;
        
                    unite(mp[i][0], j, parent);
   
            }
        }

        return  true;
    }
};