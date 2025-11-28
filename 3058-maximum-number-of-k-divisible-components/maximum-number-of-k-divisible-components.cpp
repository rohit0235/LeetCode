class Solution {
public:
    int solve(int n, vector<vector<int>>& adj, vector<int>& values, int& count,
              int parent, int curr, int k) {

        int sum = values[curr];

        for (int nbr : adj[curr]) {
            if (nbr != parent) {
                sum += solve(n, adj, values, count, curr, nbr, k);
            }
        }

        sum %= k;
        if (sum == 0)
            count++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {

        int count = 0;
        vector<vector<int>> adj(n);

        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        solve(n, adj, values, count, -1, 0, k);
        return count;
    }
};