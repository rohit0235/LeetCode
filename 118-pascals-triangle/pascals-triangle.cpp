class Solution {
public:
    vector<vector<int>> generate(int numRows) {


            vector<vector<int>>res;
            res.push_back({1});
            for(int i=1;i<numRows;i++){
                       
                       vector<int>curr(i+1,1);
                       for(int j=1;j<i;j++){
                                   
                                   vector<int>prev= res.back();
                                   curr[j]=prev[j-1]+prev[j];

                       }        

                       res.push_back(curr); 
                  
            }

            return res;









             
            //  vector<vector<int>>result;
            //  for (int i=0;i<numRows;i++){
                    
            //         vector<int>rows(i+1,1);

            //         for (int j=1;j<i;j++){
            //             rows[j]=result[i-1][j]+result[i-1][j-1];
            //         }

            //         result.push_back(rows);


            //  }
            //  return result;




    }
};