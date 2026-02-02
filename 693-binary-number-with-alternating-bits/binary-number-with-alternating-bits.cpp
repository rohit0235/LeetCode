class Solution {
public:
    bool hasAlternatingBits(int n) {
         
         int prev=-1;

         while (n){
              int k= n%2;
             
              if( k!=prev){
                  prev = k;  
              }
              else {
                 return false;
              }

              n=n>>1;
            //   cout<<n<<endl;
         }
         return true;

    }
};