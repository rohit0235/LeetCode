class Solution {
public:
    vector<int> solve(unordered_map<int, vector<int>>& adj,
                      vector<int>& indegree, int numCourses) {

        vector<int> result;
        queue<int> q;
        int count = 0;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {

                q.push(i);
            }
        }

        while (!q.empty()) {

            int u = q.front();
            q.pop();
            result.push_back(u);  // Add the current course to the topological order
            count++; // Increment the count of processed courses
            for (auto v : adj[u]) {

                // q.push(v);
                indegree[v]--;
                if (indegree[v] == 0) {
                    // result.push_back(v);
                    // count++;
                     q.push(v);
                }
            }
        }

        if (count == numCourses)
            return result;
        else
            return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto i : prerequisites) {

            int u = i[0];
            int v = i[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        return solve(adj, indegree, numCourses);
    }
};