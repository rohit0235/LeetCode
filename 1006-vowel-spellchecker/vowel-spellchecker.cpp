class Solution {
public:
    // FIX 1: Added 'E' to the list of uppercase vowels.
string cv(string j) {
        string ans = "";
        for (char i : j) {
            char lower_char = tolower(i);
            if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
                ans.push_back('*'); // Replace vowel with a placeholder
            } else {
                ans.push_back(lower_char); // Append lowercase consonant
            }
        }
        return ans;
    }
    vector<string> spellchecker(vector<string>& wl, vector<string>& queries) {
        // Using the same variable names as in the original code
        unordered_map<string, int> mp;
        unordered_map<string, string> mp2;
        unordered_map<string, string> mp3;

        // --- Step 1: Populate all maps correctly ---

        // Populate map for exact matches (mp)
        for (const string& i : wl) {
            mp[i]++;
        }

        // FIX 2: Corrected logic to populate map for case-insensitive matches (mp2)
        for (const string& i : wl) {
            string lower_word = i;
            transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::tolower);
            // Store the first original word we see for a given lowercase version
            if (mp2.find(lower_word) == mp2.end()) {
                mp2[lower_word] = i;
            }
        }
        
        // FIX 3: Corrected logic to populate map for vowel errors (mp3)
        for (const string& i : wl) {
            string lower_word = i;
            transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::tolower);
            string devoweled_word = cv(lower_word);
            // Store the first original word we see for a given devoweled version
            if (mp3.find(devoweled_word) == mp3.end()) {
                mp3[devoweled_word] = i;
            }
        }

        // --- Step 2: Process queries using the populated maps ---

        // FIX 4: Create an answer vector of the correct size to fill in results
        vector<string> ans(queries.size());

        // Process each query with the 3 rules in order of priority
        for (int i = 0; i < queries.size(); i++) {
            string current_query = queries[i];

            // Rule 1: Exact match
            if (mp.count(current_query)) {
                ans[i] = current_query;
                continue;
            }

            // Rule 2: Case-insensitive match
            string lower_query = current_query;
            transform(lower_query.begin(), lower_query.end(), lower_query.begin(), ::tolower);
            if (mp2.count(lower_query)) {
                ans[i] = mp2[lower_query];
                continue;
            }

            // Rule 3: Vowel-error match
            string devoweled_query = cv(lower_query); // cv needs the lowercase version
            if (mp3.count(devoweled_query)) {
                ans[i] = mp3[devoweled_query];
                continue;
            }

            // If no match is found after all checks, the answer is an empty string
            ans[i] = "";
        }

        return ans;
    }
};