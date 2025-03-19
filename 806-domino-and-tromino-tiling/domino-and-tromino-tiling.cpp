class Solution {
public:
    int numTilings(int n) {
       
          // 1 2 5 11 24 53 106+
         
          vector<int>s(n,0);
          if (n==1) return 1;
          if (n==2) return 2;
          if (n==3) return 5;

          s[0]=1;
          s[1]=2;
           s[2]=5;
          for(int i=3;i<n;i++){

                s[i]=((s[i-1]*2)%1000000007+s[i-3])%1000000007; 
                  
          }

          return s[n-1];
        
    }
};