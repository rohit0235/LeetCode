class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans =target;
        char mini = letters[0];
        for(char i:letters){
              if(i>ans){ 
                if(ans==target) ans =i;
                 else  ans = min(ans, i);
                 
              }
            //   mini = min(mini, i);
        }

        return ans==target ? mini : ans;
    }
};