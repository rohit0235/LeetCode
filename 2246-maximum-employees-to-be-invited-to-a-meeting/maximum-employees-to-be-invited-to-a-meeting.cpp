class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        
            int n = fav.size();
        vector<int> inDeg(n, 0), depth(n, 1);
        for (int i{0}; i < n; ++i) inDeg[fav[i]]++;
        queue<int> q;
        for (int i{0}; i < n; ++i) if (inDeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int nxt = fav[cur];
            depth[nxt] = max(depth[nxt], depth[cur] + 1);
            if (--inDeg[nxt] == 0) q.push(nxt);
        }
        int maxCycle{0}, twoCycleSum{0};
        for (int i{0}; i < n; ++i) {
            if (inDeg[i] == 0) continue;
            int len{0}, cur = i;
            while (inDeg[cur] != 0) {
                inDeg[cur]=0;
                len++;
                cur = fav[cur];
            }
            if (len == 2) {
                twoCycleSum += depth[i] + depth[fav[i]];
            } else {
                maxCycle = max(maxCycle, len);
            }
        }
        return max(maxCycle, twoCycleSum);

        // int n =favorite.size();

        // int maxi=0;

        // for (int i=0;i<n;i++){
             
        //      set<int>s;
        //      s.insert(i);
             
        //      int current=favorite[i];
          
        //     while (s.insert(current).second){
                  
        //             //  cout<<current<<" "<<i<<" "<<endl;
        //          s.insert(current);
        //          current=favorite[current];
        //            int soz=s.size();
        //         maxi=max(maxi,soz);
        //      }
        //     //  cout<<current<<" "<<endl;
        //      int soz=s.size();
        //      if (favorite[current]==favorite[i]){
                      
        //              maxi=max(maxi,soz);
        //      }

     
        // }
        // return maxi;
    }

    };
    static auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return nullptr; }();

