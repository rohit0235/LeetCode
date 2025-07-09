class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
                  
             char ans=' ';

             for(char i:letters){
                 if (i>target && (ans==' ' || i<ans)){
                      ans=i;
                 }
             }  
             if (ans==' ') return letters[0];   
                   return ans;           
    }
};