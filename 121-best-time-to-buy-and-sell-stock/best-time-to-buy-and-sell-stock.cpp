class Solution {
public:
    int maxProfit(vector<int>& prices) {

        
        int maxp=0;
          int n =prices.size();
       int bestb=prices[0];
       for (int i=1;i<n;i++){
                if (bestb<prices[i]){
                      maxp=max(maxp,prices[i]-bestb);
                }
               bestb=min(bestb,prices[i]);
       }
       return maxp;





    //    for (int i=1;i<n;i++){
              
    //        if (prices[i]>bestb){
    //         maxp=max(maxp,prices[i]-bestb);
    //        }
    //      bestb=min(bestb,prices[i]);

    //    }

    //    return maxp;








        //   vector <int>maxo(n);
        //   int maxi=INT_MIN;
        //   for (int i=n-1;i>=0;i--){
        //       maxi=max(maxi,prices[i]);
        //       maxo[i]=maxi;
        //   }
       
        //   for (int i=0;i<n;i++){
        //        maxp=max(maxp,maxo[i]-prices[i]);
        //   }
        //   return maxp;


        // for (int i=0;i<n;i++){
        //    int maxi=*max_element(prices.begin()+i,prices.end());
        //    maxp=max(maxp,maxi-prices[i]);    
           
        // }
        // return maxp;


    }
};