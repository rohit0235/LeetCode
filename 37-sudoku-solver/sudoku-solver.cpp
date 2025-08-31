class Solution {
public:
   
   bool safe(vector<vector<char>>&board ,  int row, int col ,char dg){

              for(int i=0;i<9;i++){ 
                          if (board[row][i]==dg) return false;
                          if (board[i][col]==dg) return false;
              }   
       
               int rowlimit = (row/3)*3;
               int collimit =( col/3)*3;


               for(int i=rowlimit;i<rowlimit+3;i++){
                 
                   for(int j=collimit;j<collimit+3;j++){
                            
                            if (board[i][j]==dg) return false;
                   }
               }

               return true;

 
        
   }
   bool solve(vector<vector<char>>&board ,  int row, int col ){
            
                if (row==9) return true;

                int newrow = row;
                int newcol = col+1;

                if (newcol==9) {
                      newcol =0;
                      newrow = row+1;
                }

                if (board[row][col]!='.') return solve(board, newrow  , newcol);

                for(int i='1';i<='9';i++){
                      if (safe(board ,row , col , i)) {
                         board[row][col] =i;

                         if (solve(board ,newrow , newcol)) return true;
                         board[row][col] ='.';

                      }
                }

                return false;
               
   }
    
    void solveSudoku(vector<vector<char>>& board) {
            
   

              solve(board ,  0 , 0);
    }
};