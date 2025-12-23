class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;

        long long num=0;
        long long num2=x;
        while (num2){
              num=num*10+(num2%10);
              num2/=10;
        }
        // cout<<num<<" "<<x;
        return num==x;
    }
};