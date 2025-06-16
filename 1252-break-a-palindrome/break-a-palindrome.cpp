class Solution {
public:
    string breakPalindrome(string palindrome) {
        string ans ="";
         int n =palindrome.size();
        if(n==1) return ans;
         
           bool flag =false;
         for(int i=0;i<n/2;i++){
                
                if (palindrome[i]!='a'){
                     palindrome[i]='a';
                     flag=true;
                     break;
                }
                
         }
        
       if (flag) return palindrome;
       
       palindrome[n-1]='b';
       return palindrome;

    }
};