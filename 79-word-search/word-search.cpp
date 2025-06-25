class Solution {
public:

int n,m,w;

bool dfs(vector<vector<char>>& board, int i ,  int j , string& word , int idx ){
     

            if (idx>=word.length()) return true;

            if (i<0 || i>=n || j<0 ||  j>=m || board[i][j]!=word[idx]){
                 return false;
            }

            char current = board[i][j];
            board[i][j]='#';

            bool f = dfs(board, i+1,j,word,idx+1)
                   || dfs(board, i,j+1,word,idx+1)
                  || dfs(board, i,j-1,word,idx+1)
                || dfs(board, i-1,j,word,idx+1);
            
            board[i][j]=current;


            return f;

}
    bool exist(vector<vector<char>>& board, string word) {
             
                  n =board.size();
                 m =board[0].size();

                  w =word.size();
                 
                //  queue<pair<int,int>>q;
                 for(int i=0;i<n;i++){
                      
                        for(int j=0;j<m;j++){
                             
                              if (board[i][j]==word[0]){
                                //    q.push({i,j});

                                      if (dfs(board, i , j ,word, 0)) return true;

                              }
                        }
                 }

                 return false;
                
                //  int j=1;
                //  while (!q.empty()){
                //               if (j>=w) return true;
                //               int  k = q.size();
                //             //   int h =j;
                //               bool flag = false;
                //               for(int s=0;s<k;s++){
                                   
                //                       pair<int,int>top = q.front();
                //                       q.pop();
                //                       int i =top.first;
                //                       int newj =top.second;
                                      
                //                       if (board[i][newj]==word[j]){
                                        
                //                          if (i+1<n) q.push({i+1,newj});
                //                          if (newj+1<m) q.push({i,newj+1});
                                      
                //                          if (i-1>=0)  q.push({i-1,newj});
                //                          if (newj-1>=0)  q.push({i,newj-1});
                //                          flag=true;
                                           
                //                       }
                                    
                                  

                                   
                //               }
                //               if (flag)j++;
                //             //   else return false;
                //             //   if (h==j) return false;
                              


                //  }

                //  return j>=w;
                 



    }
};