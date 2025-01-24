class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candles, int extraCandies) {
                int n=candles.size();
                vector<bool>s(n,true);
                int maxi=0;
                for (int i:candles){
                    maxi=max(maxi,i);
                }
                for (int   j=n-1;j>=0;j--){
                       
                       if (candles[j]+extraCandies<maxi){
                              s[j]=false;
                       }
                   

                }
                // int maxi=0;
                // for (int i:candles){
                //        maxi=max(maxi,i);
                // }
                // for (int i=0;i<n;i++){
                //     int find=candles[i]+extraCandies;

                //      if (find<maxi){
                //                 s[i]=false;
                          
                //         }   
           


                // }

      return s;







    }
};