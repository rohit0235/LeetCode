class Solution {
public:
    int countPrimeSetBits(int left, int right) {
         unordered_set<int>st={2,3,5,7,11,13,17,19};
         int c=0;
         for(int i=left;i<=right;i++){
              
               int count = __builtin_popcount(i);
               if (st.find(count)!=st.end()){
                 c++;
               }


         }


         return c;
    }
};