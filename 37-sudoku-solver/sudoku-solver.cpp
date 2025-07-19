class Solution {
public:
    bool issafe(vector<vector<char>>& board,char dig , int row , int col){
          
            for(int i=0;i<9;i++){
                  if (board[row][i]==dig) return false;
                  if (board[i][col]==dig) return false;
            }

            int fr = (row/3)*3;        
            int fc = (col/3)*3;

            for(int i=fr;i<fr+3;i++){
                 
                  for(int j= fc;j<fc+3;j++){
                          
                         if (board[i][j]==dig) return false;
                  }
            }        

            return true;
           
    }
    bool help(vector<vector<char>>& board, int row , int col){
                 
                  if (row==9) return true;
                  int newrow = row;
                  int newcol = col+1;
                  if (newcol==9){
                     newrow = row+1;
                     newcol=0;
                  }
                  if (board[row][col]!='.'){
                       return help(board , newrow , newcol);
                  }
 
                  for(char i='1';i<='9';i++){

                          if (issafe(board, i,row, col)){
                                      board[row][col]=i;
                               if (help(board, newrow, newcol)) return true;
                                board[row][col]='.';
                          }                           

                   
                           
                  }
                  return false;

              

    }
 
  
    void solveSudoku(vector<vector<char>>& board) {
            
             int row = board.size();
             int col = board[0].size();
          
            help(board , 0,0);
    }
};