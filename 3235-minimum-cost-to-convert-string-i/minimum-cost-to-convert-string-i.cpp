class Solution {
public:
    long long dji(char source, char target,
                  map<char, vector<pair<char, int>>>& mp) {

        vector<int> dist(26, INT_MAX);
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
        pq.push({0, source});

        dist[source - 'a'] = 0;

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int wei = top.first;
            int u = top.second - 'a';

            for (auto p : mp[top.second]) {

                int v = p.first - 'a';
                int w2 = p.second;

                if (dist[u] + w2 < dist[v]) {
                    dist[v] = dist[u] + w2;
                    pq.push({dist[v], p.first});
                }
            }
        }

        return dist[target - 'a'];
    }
    long long minimumCost(string source, string target, vector<char>& ord,
                          vector<char>& chi, vector<int>& cost) {

        map<char, vector<pair<char, int>>> mp;

        for (int i = 0; i < ord.size(); i++) {
            mp[ord[i]].push_back({chi[i], cost[i]});
        }
        // long long ans = 0;

        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));

        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        for (int i = 0; i < ord.size(); i++) {
            int first = ord[i] - 'a';
            int second = chi[i] - 'a';
            int third = cost[i];

            dist[first][second] = min(dist[first][second], third);
        }

        for (int k = 0; k < 26; k++) {

            for (int i = 0; i < 26; i++) {

                for (int j = 0; j < 26; j++) {
                    if(dist[i][k]!=INT_MAX  &&  dist[k][j]!=INT_MAX )
                       dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        
        long long ans =0;
        for(int i=0;i<target.size();i++){
                          if (source[i] != target[i]) {
                                   int sc= source[i]-'a';
                                   int tar= target[i]-'a';
                                    long long che=dist[sc][tar];

                                    if(che>=INT_MAX) return -1;
                                ans+=che;
                         }
        }

        return ans==INT_MAX ? -1 :ans;
        // for (int i = 0; i < source.size(); i++) {

        //     if (source[i] != target[i]) {
        //         ans += dji(source[i], target[i], mp);
        //     }
        // }

        // return ans>=INT_MAX ? -1 : ans;
    }
};