class Solution {
public:
         int n,m;
      void dfs(vector<vector<char>>&grid, int i, int j){
            
            if (i<0 || i>=n || j>=m || j<0 || grid[i][j]=='0' || grid[i][j]=='$'  ){
                  return ;
            }


            grid[i][j]='$';

            dfs(grid,i+1,j);
            dfs(grid,i-1,j);
            dfs(grid,i,j+1);
            dfs(grid,i,j-1);
          
      }
 
    int numIslands(vector<vector<char>>& grid) {
            int count =0;
            n = grid.size();
            m = grid[0].size();
           for(int i=0;i<grid.size();i++){
                  
                  for (int j=0;j<m;j++){
                      
                         if (grid[i][j]=='1'){
                                 
                                dfs(grid,i,j);
                                //  grid(i,j)
                                count++;

                        }
                     
                  }

           }


           return count;


    }
};