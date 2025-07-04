class Solution {
public:

      int solve(int copy , int clip , int n){
           
            if (copy==n) return 0;

            if (copy>n) return 1000000;

            int copyandpaste =1+1+ solve(copy+copy,copy , n);
            int paste= 1+solve(copy+clip ,clip , n);

            return min(copyandpaste,paste )   ;         
            
      }

    int minSteps(int n) {
        if (n==1) return 0;


        return 1+solve(1,1,n);
    }
};