class Solution {
public:
    bool rotateString(string s, string goal) {
        if (goal.size()!=s.size()) return false;
        if ((s+s).find(goal)!=string::npos){
              return true;
        }
        return false;
    }
};