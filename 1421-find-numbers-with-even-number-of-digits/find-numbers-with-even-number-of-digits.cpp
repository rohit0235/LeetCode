class Solution {
public:

     int numdigits(int c){
           
           int count=0;
           while (c){
   
              c=c/10;
              count++;
           }

           return count;

     }
    int findNumbers(vector<int>& nums) {
        
             int ans=0;

             for(int i:nums){
                 if (numdigits(i)%2==0){
                     ans++;
                 }
             }

             return ans;
         
    }
};