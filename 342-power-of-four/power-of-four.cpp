class Solution {
public:
    bool isPowerOfFour(int n) {
            
            if (n==1) return true;
            if (n<=0) return false;

            while (n>4){
                if (n%4!=0) return false;
               n =n/4;
            }

            return n%4==0;


    }
};