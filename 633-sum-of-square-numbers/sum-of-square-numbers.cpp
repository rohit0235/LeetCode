class Solution {
public:
    bool judgeSquareSum(int c) {
         
         for(int i=0;i<=sqrt(c);i++){
                
                int check = c - (i*i);
                
                int sqr=sqrt(check);
                if (sqr*sqr==check){
                     return true;
                }
                 

         }

         return false;
                

    }
};