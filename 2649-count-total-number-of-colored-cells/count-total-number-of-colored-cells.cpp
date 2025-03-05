class Solution {
public:
    long long coloredCells(int n) {
         if (n==1) return 1;
         long long start=0;
         long long ans=1;
         for (int i=0;i<n-1;i++){
               
               start+=4;
               ans+=start;

         }

         return ans;
    }
};