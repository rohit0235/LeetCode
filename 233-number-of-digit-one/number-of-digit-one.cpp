class Solution {
public:
    int countDigitOne(int ne) {

        string s = to_string(ne);
        if (ne == 1)
            return 1;
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {

            if (s[i] == '0') {
                continue;

            } else if (s[i] != '1') {

                int curr = pow(10, n - i - 1);

                int multip = curr + (s[i] - '0') * (n - i - 1) * (curr / 10);

                res += multip;

            } else {

                if (i == n - 1)
                    res++;

                string su = s.substr(i + 1);
                int number = 0;
                if (!su.empty()) {
                    number = stoi(su) + 1;
                }

                int lowerdigits = ((n - i - 1) * pow(10, n - i - 1)) / 10;

                res += lowerdigits + number;
            }
        }

        return res;
    }
};