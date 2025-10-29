class Solution {
public:
    int smallestNumber(int n) {
             
              // 1 3 7 15 31   
              int check=1;
              while (check<n){
                 check=check*2+1;
              } 
                // check=check*2+1;
              return check;
           
    }
};