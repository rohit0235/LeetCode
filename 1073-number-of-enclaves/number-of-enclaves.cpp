class Solution {
public:
vector<int>dx = {-1,0,1,0};
vector<int>dy = {0,1,0,-1};

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
               if (grid[i][0]==1){
                      q.push({i,0});
                      grid[i][0]=-1;
               }
               if (grid[i][m-1]==1){
                      q.push({i,m-1});
                      grid[i][m-1] = -1;
               }
   
        }  
        for(int i=0;i<m;i++){
               if (grid[0][i]==1){
                      q.push({0,i});
                      grid[0][i] = -1;
               }
               if (grid[n-1][i]==1){
                      q.push({n-1,i});
                      grid[n-1][i]=-1;
               }
   
        }  

        while (!q.empty()){
              
              pair<int,int>front = q.front();
              q.pop();
              for(int  i =0;i<4;i++){
                   int nx = front.first + dx[i];
                   int ny = front.second + dy[i];

                   if (nx>=0 && nx<n && ny<m && ny>=0 && grid[nx][ny]==1){
                        grid[nx][ny] =0;
                        q.push({nx,ny});
                   }
              }
              
        }

        int ans =0;
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if (grid[i][j]==1) ans++;
             }
        }
        return ans;
        
    }
};