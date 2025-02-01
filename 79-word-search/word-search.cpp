class Solution {
public:
         vector<vector<int>>dire={{-1,0},{0,-1},{1,0},{0,1}};
  bool find(vector<vector<char>>& board, string &word,int i,int j,int index,int n,int m){
                 
                 if (index==word.size()) return true;
                 
            if (i<0 || i>=n || j<0 || j>=m || board[i][j]=='$') return false;
                 if (board[i][j]!=word[index]) return false;
                  char temp=board[i][j];
                  board[i][j]='$';
                 for (auto &dir:dire){
                       
                       int newx=i+dir[0];
                       int newy=j+dir[1];
                        if (find(board,word,newx,newy,index+1,n,m)){
                            return true;
                        }
                     
                 }
                    board[i][j]=temp;
                 return false;
                 
    }
    bool exist(vector<vector<char>>& board, string word) {
           
           int n =board.size();
           int m=board[0].size();

           for (int i=0;i<n;i++){
                
                for (int j=0;j<m;j++){
                      
                      if (board[i][j]==word[0]  && find(board,word,i,j,0,n,m)){
                           return true;
                      }
                }
           }

           return false;


    }
};