class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
          // 2 4 6 8  x=2-> 
     
         vector<int>check;
     

         for(int i=0;i<grid.size();i++){
              for(int j=0;j<grid[0].size();j++){
                 check.push_back(grid[i][j]);
              }
         }  
             int n=check.size();   
         if (n==1) return 0;
        sort(check.begin(),check.end());
        int median =0;
        //  if (n%2!=0) median =check[(n+1)/2];
          median=check[n/2];
       int count=0;
       for(int i=0;i<n;i++){
             
             int diff=abs(median-check[i]);

             if (diff%x!=0){
                  return -1;
             }
             else{
                  count+=diff/x;
             }
            
       }

       return count;

         
    }
};