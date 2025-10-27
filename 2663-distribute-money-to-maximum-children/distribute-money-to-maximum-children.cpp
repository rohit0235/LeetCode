class Solution {
public:
    int distMoney(int money, int children) {
            int count =0;
            if (money<children ) return -1;
            if (money==children ) return 0;

           while (children--){
                    //  cout<<children;
                     if (children==1){
                          if(money-8>0 && money-8!=4){
                                count++;
                               money=money-8;
                          }
                          else{
                              money = 1;
                          }
                     }
                     else if (children==0){
                         if (money ==8 )return count+1;
                         else return count;
                     }
                     else{ 
                           if (money-8>=children){
                             count++;
                             money=money-8;
                           }
                           else{
                                  money=money-1;
                           }

                     }
                
           } 

           return count;

    }
};