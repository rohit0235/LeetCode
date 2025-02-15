class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
           int m =grid.size();
           int n =grid[0].size();
           queue<pair<int,int>>q;
           int total=0;
           int rotten=0;
           int time =0;
           for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==2 || grid[i][j]==1) total++;
                if (grid[i][j]==2) q.push(make_pair(i,j));
            }
           }
           if (total==0) return 0;
           while (!q.empty()){
                   
                 int size=q.size();
                 rotten+=size;
                 if (rotten==total) return time;
                 
                  time ++;
                  for (int i=0;i<size;i++){

                         pair<int,int>pa=q.front();

                         if (pa.second+1<n && grid[pa.first][pa.second+1]==1){
                                    grid[pa.first][pa.second+1]=2;
                                 q.push(make_pair(pa.first,pa.second+1));
                         }
                         if (pa.second-1>=0 && grid[pa.first][pa.second-1]==1){
                                    grid[pa.first][pa.second-1]=2;
                                 q.push(make_pair(pa.first,pa.second-1));
                         }
                         if (pa.first+1<m && grid[pa.first+1][pa.second]==1){
                                    grid[pa.first+1][pa.second]=2;
                                 q.push(make_pair(pa.first+1,pa.second));
                         }
                         if (pa.first-1>=0 && grid[pa.first-1][pa.second]==1){
                                    grid[pa.first-1][pa.second]=2;
                                 q.push(make_pair(pa.first-1,pa.second));
                         }
                          
                            q.pop();
                  }
           }
           return -1;



    }
};