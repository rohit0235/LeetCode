class Solution {
public:
    void rotate(string& curr, int b) {

        reverse(curr.begin(), curr.end());
        reverse(curr.begin(), curr.begin() + b);
        reverse(curr.begin() + b, curr.end());
    }
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();

        string ans = s;
        queue<string> q;
        q.push(s);
        unordered_set<string> visited;

        visited.insert(s);

        while (!q.empty()) {

            string curr = q.front();
            q.pop();

            if (curr < ans)
                ans = curr;
            string temp = curr;
            for (int i = 1; i < curr.size(); i += 2) {
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }

            if (!visited.count(temp)) {
                visited.insert(temp);
                q.push(temp);
            }

            rotate(curr, b);
            if (!visited.count(curr)) {
                visited.insert(curr);
                q.push(curr);
            }
        }

        return ans;
    }
};