class Solution {
public:
    int n,m;

    void solve(vector<vector<char>>& grid,  int i, int j, vector<vector<bool>>&vis){
            
             if (i>=n || i<0 || j>=m || j<0 || grid[i][j]=='0' || vis[i][j]==true) return ;

             vis[i][j]= true;
             solve(grid, i+1,j,vis);
             solve(grid, i,j-1,vis);
             solve(grid, i,j+1,vis);
             solve(grid, i-1,j,vis);

              
    }
    int numIslands(vector<vector<char>>& grid) {
        
        n= grid.size();
        m= grid[0].size();
       vector<vector<bool>>vis(n,vector<bool>(m,0));
        int count = 0; 
                for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                    
                    if (!vis[i][j] && grid[i][j]=='1'){
                         count++;
                         solve(grid , i , j , vis);
                    }
                    
              }
        }

        return count ;

    }
};