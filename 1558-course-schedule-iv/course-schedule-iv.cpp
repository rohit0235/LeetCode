class Solution {
public:
      bool dfs(int current, int target, unordered_map<int, vector<int>>& graph, vector<vector<int>>& memo){
         if (memo[current][target] != -1) {
        return memo[current][target];
    }
    for (int neighbor : graph[current]) {
        if (neighbor == target || dfs(neighbor, target, graph, memo)) {
            return memo[current][target] = true;
        }
    }

    return memo[current][target] = false;
      }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
         unordered_map<int , vector<int>> graph;

         for(const auto& prereq : prerequisites){
            graph[prereq[0]].push_back(prereq[1]);
         }

             vector<vector<int>> memo(numCourses, vector<int>(numCourses, -1));

             vector<bool> answer;
    for (const auto& query : queries) {
        answer.push_back(dfs(query[0], query[1], graph, memo));
    }

    return answer;


    }
};