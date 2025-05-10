class Solution {
public:
    int trailingZeroes(int n) {
         
         int ft=0;
         int ff=0;

         for(int i=2;i<=n;i++){
                 
                 int temp=i;
                 while (temp%2==0){
                     ft++;
                    temp=temp/2;

                 }
                 temp=i;
                 while (temp%5==0){
                     ff++;
                     temp=temp/5;

                 }



         }


         return  min(ff,ft);
    }
};