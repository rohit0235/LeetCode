class Solution {
public:
    

    bool isPowerOfTwo(int n) {
         return n > 0 && (n & (n - 1)) == 0;
    //     if (n==1) return true;
    //     if (n%2!=0 || n<=0) return false;
        
    //    return __builtin_popcount(n)==1;

        // long long sum=1;
        // for (int i=0;i<=sqrt(abs(n))+1;i++){
        //     // cout<<sum<<" ";
        //       if (sum==abs(n)) return true;
        //       else if (sum>abs(n)) return false;

        //       sum*=2;

        // } 

        // return false;

        double remainder = fmod(n, log10(2));

        return remainder==0;
     }
};