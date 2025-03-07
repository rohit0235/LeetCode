class Solution {
public:
   bool isprime(int nums){
           if (nums<=1) return false;
           if (nums==2)  return true;
           
           for(int i=2;i<=sqrt(nums);i++){
                    if(nums%i==0) return false;
           }
           return true;

   }
    vector<int> closestPrimes(int left, int right) {
         
          vector<int>ans2;
          for(int i=left;i<=right;i++){
                  if (isprime(i)) ans2.push_back(i);
          }
        //   for(int i:ans2) cout<<i<<endl;
           if (ans2.size()<2) return {-1,-1};
           vector<int>ans;
           int mindiff=INT_MAX;
          for(int i=0;i<ans2.size()-1;i++){
                int diff=ans2[i+1]-ans2[i];
                if (diff<mindiff){
                      ans={ans2[i],ans2[i+1]};
                      mindiff=diff;
                }
          }
          return ans;




    }
};