class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    //    0 2 2 4       0 4 4 5        1 0 5 2     3 2 5 3
          //  2 2  
     
      
          vector<vector<int>>xnodes;
          vector<vector<int>>ynodes;
          
          for(int i=0;i<rectangles.size();i++){
                   xnodes.push_back({rectangles[i][0],rectangles[i][2]});
                   ynodes.push_back({rectangles[i][1],rectangles[i][3]});
                
          }

        //   vector<vector<int>>mergex;
           vector<vector<int>> res1;
        sort(xnodes.begin(),xnodes.end());
        for(int i =0;i<xnodes.size();i++){
            if(res1.empty() || xnodes[i][0] >= res1.back()[1]){
                res1.push_back(xnodes[i]);
            }
            else {
                res1.back()[1] = max(res1.back()[1] , xnodes[i][1]); 
            }
        }
         
           vector<vector<int>> res2;
        sort(ynodes.begin(),ynodes.end());
        for(int i =0;i<ynodes.size();i++){
            if(res2.empty() || ynodes[i][0] >= res2.back()[1]){
                res2.push_back(ynodes[i]);
            }
            else {
                res2.back()[1] = max(res2.back()[1] , ynodes[i][1]); 
            }
        }
        
        return res1.size()>=3 || res2.size()>=3;
        
 
    }

}; 