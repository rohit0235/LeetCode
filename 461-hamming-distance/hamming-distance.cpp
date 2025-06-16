class Solution {
public:
    int hammingDistance(int x, int y) {
          
           int c=0;
           int a=x;
           int b=y;
           while (a>0 || b>0){

                if ((a&1)!=(b&1)) c++;
                a=a>>1;
                b=b>>1;
                // cout<<a<<" "<<b<<" "<<endl;
           }  

           return c;



    }
};