class Solution {
public:
    vector<string> result;

    void solve(string& digits, string& temp, unordered_map<char, string>& mp,
               int idx) {

        if (idx >= digits.size()) {
            result.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for (int i = 0; i < str.size(); i++) {

            temp.push_back(str[i]);

            solve(digits, temp, mp, idx + 1);

            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (digits.length()==0) return {};
        unordered_map<char, string> mp = {
            {'2' ,"abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"}

        };  
   
        string temp = "";

        solve(digits, temp, mp, 0);
            if (result[0]=="") return {};
        return result;
    }
};