class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();

        // place corridor check if it is correct 
        // number of subarray divisoon that can cbe divided into 
          int ts = 0;
          for(char i:corridor)if (i=='S')ts++;
          if (ts<2) return 0;
          if (ts%2==1) return 0;
          if (ts==2) return 1;
          // checking leftsum , rightsum

          const long long mod = 1e9+7;
          long long curr =0;
          long long prev =1;
          long long mains = 0;
          for(char i:corridor){
                if (i=='S'){
                     curr++;
                     ts--;
                 }
                 if (curr==2){
                     mains++;
                 }
                 if (curr >2){
                   
                     prev = ((prev)%mod*(mains)%mod)%mod;
                     curr =1;
                     mains=0;
               }
        
                   if (ts<2) return prev;
                    mains%=mod;
                    prev = prev%mod;
                //  cout<<curr<<" "<<prev<<endl;
          }

          return prev;

         
    }
};