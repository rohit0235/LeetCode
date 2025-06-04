class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        vector<bool> check(26, 0);
        
        if(numFriends==1) return word;
        for (int i = 0; i < n; i++) {

            int index = word[i] - 'a';

            check[index] = true;
        }
         
        char ch = ' ';
        for (int i = 0; i < 26; i++) {

         

            if (check[i] == true) {
                ch = i+'a';
            }
        }
        // cout<<ch<<endl;

        vector<int> idx;
        for (int i = 0; i < n; i++) {

            if (word[i] == ch) {
                idx.push_back(i);
            }
        }
        
        string ans ="";
        
        for(int i:idx){
             
             int m =n-numFriends+1;

             string h = word.substr(i,m);
             
             if (h>ans){
                 ans=h;
             }
        }

        return ans;
        


    }
};