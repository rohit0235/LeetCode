class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
         int r= mat.size();
         int c= mat[0].size();

         vector<vector<int>>store(r, vector<int>(c,0));
         
         for(int i=0;i<r;i++){
                int d= 0;
                for(int j=c-1;j>=0;j--){
                       
                        if (mat[i][j]==1)d++;
                        else d=0;
                        // cout<<c<<endl;
                        store[i][j]=d;
                      
                }
         }
        //  for(int i=0;i<r;i++){
             
        //         for(int j=c-1;j>=0;j--){
                       
        //         cout<<store[i][j]<<" ";
                      
        //         }

        //         cout<<endl;
        //  }
         
         int ans =0;
         for(int i=0;i<r;i++){
      
                for(int j=0;j<c;j++){
                       int x =INT_MAX;
                     for(int k=i;k<r;k++){
                          
                           x= min(x, store[k][j]);
                                    
                           ans+=x;
                     }
                      
                }
         }
        return ans;

         
    }
};