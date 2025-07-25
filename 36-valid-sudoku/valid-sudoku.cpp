class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
            
            int n =board.size();
            int m =board[0].size();
            for(int i=0;i<n;i++){
                  unordered_set<char>st1;
                  unordered_set<char>st2;
                  for(int j=0;j<m;j++){
                                 if (board[i][j]=='.') continue;

                        if (st1.find(board[i][j])!=st1.end()){
                              return false;
                        }
                        // if (st2.find(board[j][i])!=st2.end()){
                        //       return false;
                        // }

                        st1.insert(board[i][j]);
                        // st2.insert(board[j][i]);
                  }

            } 

            for(int i=0;i<n;i++){
                //   unordered_set<char>st1;
                  unordered_set<char>st2;
                  for(int j=0;j<m;j++){
                                 if (board[j][i]=='.') continue;

                        // if (st1.find(board[i][j])!=st1.end()){
                        //       return false;
                        // }
                        if (st2.find(board[j][i])!=st2.end()){
                              return false;
                        }

                        // st1.insert(board[i][j]);
                        st2.insert(board[j][i]);
                  }

            } 
for (int i = 0; i < 9; i += 3) { // Iterate through starting rows of 3x3 blocks
                for (int j = 0; j < 9; j += 3) { // Iterate through starting columns of 3x3 blocks
                    unordered_set<char> st; // Set for current 3x3 block
                    for (int row = i; row < i + 3; row++) {
                        for (int col = j; col < j + 3; col++) {
                            if (board[row][col] == '.') {
                                continue;
                            }
                            if (st.find(board[row][col]) != st.end()) {
                                return false; // Duplicate found in this 3x3 block
                            }
                            st.insert(board[row][col]);
                        }
                    }
                }
            }


            return true;

             
    }
};