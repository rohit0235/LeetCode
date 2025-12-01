class Solution {
public:
   
   bool ispos(long long mid ,vector<int>&b , int n){
           
          long long  target = mid*n;
          long long  sum =0;
          for(int i:b){ 
              sum += std::min((long long)i, mid);
            //   sum+=min((b[i],mid);
              if (sum>=target) return true;
          }
          return false;

   }
  
    long long maxRunTime(int n, vector<int>& b) {
         
         long long  l =0;
         long long r =accumulate(b.begin(),b.end(),0LL);
         long  long ans = 0;
         while (l<=r){
              
                long long mid = l+(r-l)/2;
                if (ispos(mid ,  b , n )){
                      ans = mid;
                      l = mid+1;
                }
                else{
                     r = mid-1;
                }
               
         }

         return ans;

    }
};