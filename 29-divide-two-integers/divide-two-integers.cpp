class Solution {
public:
    int divide(int dividend, int divisor) {
            
               long long result = (long long )dividend/divisor;

               if (result>INT_MAX) return INT_MAX;
               else if (result<INT_MIN) return INT_MIN;
                
              return (long long )dividend/divisor;
            //   long long int sum=0;
            //   int  count=0;
              
            //   while (sum<=abs(dividend)){
            //     sum=sum+abs(divisor);
            //     count+=1;
            //   }
            //   if ((dividend<0 && divisor<0) ||  (dividend>0 && divisor>0)) {
            //     return (count-1);
            //   }
            //   return -1*(count-1);
    }
};