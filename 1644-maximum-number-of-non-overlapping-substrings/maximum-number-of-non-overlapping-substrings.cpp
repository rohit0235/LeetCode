class Solution {
public:
    // Function to check if substring contains all
    // occurrences of each character of str or not
    int checkValid(string str, int i, int L[], int R[]) {

        // Stores rightmost index of str[i]
        int right = R[str[i] - 'a'];

        // Traverse the current substring
        for (int j = i; j < right; j++) {

            // If leftmost index of str[j]
            // less than i
            if (L[str[j] - 'a'] < i)
                return -1;

            // Update right
            right = max(right, R[str[j] - 'a']);
        }

        return right;
    }

    // Function to find maximum number of substring
    // that satisfy the condition
    vector<string> maxNumOfSubstrings(string str) {

        // Stores all substrings that
        // satisfy the condition
        vector<string> res;

        // Stores length of str
        int n = str.length();

        // Stores leftmost index
        // of each character
        int L[26];

        // Stores rightmost index
        // of each character
        int R[26];

        // Initialize L[] and R[]
        for (int i = 0; i < 26; i++) {

            // Initialize L[i]
            // and R[i]
            L[i] = R[i] = -1;
        }

        // Traverse the string
        for (int i = 0; i < n; i++) {

            // If str[i] not
            // already occurred
            if (L[str[i] - 'a'] == -1) {

                // Update leftmost index
                // of str[i]
                L[str[i] - 'a'] = i;
            }

            // Update rightmost index
            // of str[i]
            R[str[i] - 'a'] = i;
        }

        // Stores rightmost index of last
        // substring inserted into res[]
        int right = -1;

        // Traverse the string
        for (int i = 0; i < n; i++) {

            // If i is leftmost index of str[i]
            if (i == L[str[i] - 'a']) {

                // Check if a new substring starting
                // from i satisfies the conditions or not
                int new_right = checkValid(str, i, L, R);

                // If the substring starting from i
                // satisfies the conditions
                if (new_right != -1) {

                    // Stores the substring starting from
                    // i that satisfy the condition
                    string sub = str.substr(i, new_right - i + 1);

                    // If the substring overlaps
                    // with another substring
                    if (new_right < right) {

                        // Stores sub to the last
                        // of res
                        res.back() = sub;
                    } else {

                        // If sub not overlaps to
                        // other string then  append
                        // sub to the end of res
                        res.push_back(sub);
                    }

                    // Update right
                    right = new_right;
                }
            }
        }
        return res;
    }
};