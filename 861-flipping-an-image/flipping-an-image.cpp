class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& mat) {
        


        
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>>res(row,vector<int>(col,0)) ;
        for(int i=0;i<row;i++){
             
             for(int j=0;j<col;j++){
                  
                  res[i][j] = !(mat [i][col-j-1]);
                  
             }
        } 


        return res;


    }
};