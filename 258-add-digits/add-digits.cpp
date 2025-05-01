class Solution {
public:
     int digitsum(int c){
             
             int sum=0;
             while(c){
                 sum=sum+(c%10);
                 c=c/10;
             }
             
             return sum;
     }
    int addDigits(int num) {
          
          int digit=num;
          while (digit>9){
               
               digit=digitsum(digit);
          }

          return digit;

    }
};