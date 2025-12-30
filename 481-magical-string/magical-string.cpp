class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;

        vector<int> s;
        s.reserve(n + 1);
        s.push_back(1);
        s.push_back(2);
        s.push_back(2);

        int head = 2;
        int count1 = 1;

        while (s.size() < n) {
            int numToAdd = s[head];
            int charToAppend = 3 - s.back();

            for (int i = 0; i < numToAdd && s.size() < n; ++i) {
                s.push_back(charToAppend);
                if (charToAppend == 1) {
                    count1++;
                }
            }
            head++;
        }

        return count1;
    }
};