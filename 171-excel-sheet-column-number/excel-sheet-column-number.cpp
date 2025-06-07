class Solution {
public:
    int titleToNumber(string s) {
         // binary-to-decimal conversion
                int result = 0;
                for (const auto& c : s)
                {
                    result *= 26;
                    result += c  - 'A' + 1;
                }

                return result;
    }
};