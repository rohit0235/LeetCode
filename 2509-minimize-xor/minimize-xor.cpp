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
             
             int  x=num1;
             int req= __builtin_popcount(num2);
             int curr=__builtin_popcount(x);

             int bit=0;
            
            if (curr<req){
                while (curr<req){
                    if (!isset(x,bit)){
                        setbit(x,bit);
                        curr++;
                    }
                    bit++;

                }
            }
           else if (curr>req){
                while (curr>req){
                    if (isset(x,bit)){
                        unsetbit(x,bit);
                        curr--;
                    }
                    bit++;

                }
            }

            return x;





    }
};