class Solution {
public:
    int countTriples(int n) {
         
         int ans =0;
         for(int i=1;i<=n;i++){
              
               for(int j=i;j<=n;j++){
                    
                     int l  = j+1;
                     int r =n;
                     int target  = i*i+j*j;
                     while (l<=r){
                          int mid = l +(r-l)/2;
                           if (mid*mid==target){
                             ans+=2;
                             break;
                           }
                           else if (mid*mid<target){
                                     l =mid+1;
                           }
                           else{
                             r= mid-1;
                           }
                     }
                    
               }
         }
         return ans;

    }
};