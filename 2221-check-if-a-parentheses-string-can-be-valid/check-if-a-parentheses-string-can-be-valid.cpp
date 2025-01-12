class Solution {
public:

    bool canBeValid(string s, string locked) {
        
        int n=s.size();
        if (n<=1) return false;
        if (n%2!=0) return false;
        int left=0;
        int right=0;
        int change=0;
         for (int i=0;i<n;i++){
               if (locked[i]=='0') change++;
               else if (s[i]=='(') left++;
               else right++;

               if (left+change<right) return false;
         }
         left=0; right=0; change=0;
         for (int i=n-1;i>=0;i--){
               if (locked[i]=='0') change++;
               else if (s[i]=='(') left++;
               else right++;

               if (right+change<left) return false;
         }
         return true;




    }
};