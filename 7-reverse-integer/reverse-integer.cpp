class Solution {
public:
    int reverse(int x) {

               long long  l=0;
               long long    n=x;
            while (n){
                 int f=n%10;
                 if (l>=INT_MAX || l<=INT_MIN ) return 0;
                 l=(l*10)+f;
                 n=n/10;
            }
            if (l>=INT_MAX || l<=INT_MIN ) return 0;
            return l;
          

    }
};