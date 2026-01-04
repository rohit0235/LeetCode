class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
         long long n = nums.size();
         long long ans =0;

         for(long long i:nums){
                 long long c=0;
                 long long temp =1+i;
                 for(long long j=2;j<i;j++){
                       if(c>2)break;
                       if(i%j==0){
                         c++;
                         temp+=j;
                       }
                 } 
                //  cout<<c<<" "<<temp<<endl;
                 if(c==2)ans+=temp;

         }

         return ans;

        

    }
};