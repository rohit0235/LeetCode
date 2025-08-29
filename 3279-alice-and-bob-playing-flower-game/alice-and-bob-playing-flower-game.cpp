class Solution {
public:
    long long flowerGame(int n, int m) {
        
          long long e1=n/2;
          long long e2=m/2;
          long long o1=n-e1;
          long long o2=m-e2;

          return (long long )e1*o2+(long long )e2*o1;
    }
};