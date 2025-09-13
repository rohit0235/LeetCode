class Solution {
public:
    int n;


    long long appealSum(string s) {
           
             int n = s.size();
        long long total_appeal = 0;

        // Using a vector is slightly faster for a fixed alphabet like lowercase English letters.
        // It stores the last seen index of each character. Initialize with -1.
        std::vector<int> last_pos(26, -1);

        for (int i = 0; i < n; ++i) {
            // Get the character and its corresponding index (0-25)
            char c = s[i];
            int char_idx = c - 'a';

            // Get the index of the previous occurrence of this character
            int prev_idx = last_pos[char_idx];

            // Calculate the contribution of the current character s[i].
            // It contributes to all substrings that start after its previous occurrence
            // and end at or after its current occurrence.
            // Number of possible start points: (i - prev_idx)
            // Number of possible end points: (n - i)
            long long contribution = (long long)(i - prev_idx) * (n - i);
            
            total_appeal += contribution;

            // Update the last seen position for the current character
            last_pos[char_idx] = i;
        }

        return total_appeal;
    }
};