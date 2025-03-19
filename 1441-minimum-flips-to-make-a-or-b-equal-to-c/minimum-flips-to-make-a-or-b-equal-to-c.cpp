class Solution {
public:
    
    
    int minFlips(int a, int b, int c) {
        //  if (a | b==c) return 0;
         int count=0;
         for(int i=31;i>=0;i--){
              
              int righta=(a>>i)&1;
              int rightb=(b>>i)&1;
              int rightc=(c>>i)&1;
            //   cout<<righta<<" "<<rightb<<" "<<rightc <<endl;
              if (rightc==0){
                     if (righta==1) count++;
                     if (rightb==1) count++;
              }
              else{
                   if (righta==0 && rightb==0) count++;
 
              }

         }
          
          return count;
    }
};