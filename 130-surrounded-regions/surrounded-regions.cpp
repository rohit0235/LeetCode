class Solution {
public:
      
      int n,m;
     void dfs(int i, int j , vector<vector<char>>&board){
          
          if (i<0 || i>=n || j<0 || j>=m || board[i][j]!='O') return ;
          board[i][j]='#';
          dfs(i+1,j,board);
          dfs(i,j+1,board);
          dfs(i,j-1,board);
          dfs(i-1,j,board);

     }

    void solve(vector<vector<char>>& board) {
                     
                    n =board.size();
                     m =board[0].size();
                     if (n==1 && m==1) return ;
                     for(int i=0;i<n;i++){
                            
                            int curr = board[i][0];
                            int curr2 = board[i][m-1];

                            if (curr=='O'){
                                  dfs(i,0 , board);
                            }
                            if (curr2=='O'){
                                    dfs(i,m-1 , board);
                            }
                     }
                     
                     for(int i=0;i<m;i++){
                            
                            int curr = board[0][i];
                            int curr2 = board[n-1][i];

                            if (curr=='O'){
                                  dfs(0,i , board);
                            }
                            if (curr2=='O'){
                                    dfs(n-1 ,i, board);
                            }
                     }

                     for(int i=0;i<n;i++){
                            
                             for(int j=0;j<m;j++){
                                  if (board[i][j]=='O'){
                                      board[i][j] = 'X';
                                  }
                                  if (board[i][j]=='#'){
                                      board[i][j] = 'O';
                                  }
                             }
                     }
                     


               


    }
};