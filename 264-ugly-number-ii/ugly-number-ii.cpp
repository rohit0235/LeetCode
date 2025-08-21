class Solution {
public:


    int nthUglyNumber(int n) {
                   
          if (n==1) return 1;

          vector<int>t(n+1,0);
          t[1]=1;
          int i2=1;
          int i3=1;
          int i5=1;
                
         for(int i=2;i<=n;i++){
                
                int first = t[i2]*2;
                int second = t[i3]*3;
                int third= t[i5]*5;
                 
                int mini = min(first,min(second,third));
            t[i]=mini;
                if (mini == first){
            
                     i2++;
                }

                if (mini == second){
                    
                     i3++;
                }

                if (mini == third){
                    
                     i5++;
                }

         }

         return t[n];
        
    }
};