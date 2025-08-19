class Solution {
public:
    long long zeroFilledSubarray(vector< int>& nums) {

               long long count =0;
               long long ans  =0;
              for( long long i:nums){
                 
                      if (i==0) count++;
                      else {
                          ans+=(count*(count+1))/2 ;
                          count =0;
                      }
                    
              }
               ans+=(count*(count+1))/2 ;
              return ans;





    }
};