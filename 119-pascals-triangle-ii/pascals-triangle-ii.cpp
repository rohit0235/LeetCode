class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>>result;
        for (int i=0;i<rowIndex+1;i++){
           vector<int>rows(i+1,1);
            for (int j=1;j<i;j++){
                 rows[j]=result[i-1][j]+result[i-1][j-1];
            }
              result.push_back(rows);
        }
      
        return result[rowIndex];
    }
};