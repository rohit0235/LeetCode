class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
             
              int m = grid.size();
              int n = grid[0].size();
              
            //   vector<int>element;
            //   for(int i=0;i<n;i++){
                       
            //             for(int j=0;j<n;j++){
            //                    element.push_back(grid[i][j]);
            //             }
                      
            //   }
            //   sort(element.begin(),element.end());
              // top right triangle

              for(int i=1;i<n;i++){
                        int j =0;
                        int k=i;
                        vector<int>elem;
                        while (k<n && j<n){
                            //    grid[j][k] =element[l];
                 elem.push_back(grid[j][k]);
                               k++;
                               j++;
                               
                      }
                       j =0;
                        k=i;
                        int idx =0;
                        sort(elem.begin(),elem.end());
                        while (k<n && j<n){
                           
                               grid[j][k] = elem[idx];
                               idx++;
                               k++;
                               j++;
                        }
           
              }
              for(int i=0;i<n;i++){
                        
                           int j =0;
                        int k=i;
                        vector<int>elem;
                        while (k<n && j<n){
                            elem.push_back(grid[k][j]);
                               k++;
                               j++;
                            
                      }
                       j =0;
                        k=i;
                        int idx =0;
                        sort(elem.rbegin(),elem.rend());
                        while (k<n && j<n){
                           
                               grid[k][j] = elem[idx];
                               idx++;
                               k++;
                               j++;
                        }
              }
              
              return grid;


    }
};