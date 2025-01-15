class Solution {
public:
    bool isset(int &x,int bit){
        return x&(1<<bit);
    }

    bool setbit(int &x,int bit){
        return x|=(1<<bit);
    }
    bool unsetbit(int &x,int bit){
        return x &= (~(1<<bit));
    }
    int minimizeXor(int num1, int num2) {
             
       int x=0;
       int req=__builtin_popcount(num2);

       for (int bit=31;bit>=0 && req>0 ;bit--){
            
            if (isset(num1,bit)){
                setbit(x,bit);
                req--;
            }
       }
       for (int bit=0;bit<=31 && req>0 ;bit++){
            
            if (!isset(num1,bit)){
                setbit(x,bit);
                req--;
            }
       }
       
       return x;
       
       
       
       
       
       
       
       
        //      int  x=num1;
        //      int req= __builtin_popcount(num2);
        //      int curr=__builtin_popcount(x);

        //      int bit=0;
            
        //     if (curr<req){
        //         while (curr<req){
        //             if (!isset(x,bit)){
        //                 setbit(x,bit);
        //                 curr++;
        //             }
        //             bit++;

        //         }
        //     }
        //    else if (curr>req){
        //         while (curr>req){
        //             if (isset(x,bit)){
        //                 unsetbit(x,bit);
        //                 curr--;
        //             }
        //             bit++;

        //         }
        //     }

        //     return x;





    }
};