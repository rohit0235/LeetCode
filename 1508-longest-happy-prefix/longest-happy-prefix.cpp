class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        
        for (int len = n - 1; len > 0; len--) {
            if (!memcmp(s.c_str(), s.c_str() + (n - len), len)) {
                return s.substr(0, len);
            }
        }

        return "";
    }
};