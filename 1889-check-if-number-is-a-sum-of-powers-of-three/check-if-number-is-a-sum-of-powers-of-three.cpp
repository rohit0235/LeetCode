class Solution {
public:
    bool checkPowersOfThree(int n) {
        // 1+9+
        // if (n<=3){
        //                 return (n%3==0 || (n-1)%3==0);
        // }
        // return (n%6==0 || (n-1)%6==0);
        // return n%6==0;
        if (n==1) return true;
         int rem=0;
        while (n){
            rem=n%3;
             n=n/3;
             if (rem==2){
                   return false;
             }
        }         if (rem==2){
                   return false;
             }
             return true;
    }
};