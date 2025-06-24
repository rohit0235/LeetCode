class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
                  int n =mat.size();
                  int m =mat[0].size();
                    vector<int>ans;

                  // find maximum element in each row (bs)

                  for(int i=0;i<n;i++){


                      int maxindex=0;
                      for(int j=0;j<m;j++){
                           
                              if (mat[i][maxindex]<mat[i][j]){
                                     maxindex=j;
                              }
                          
                      }
                     
                        //   int l =0;
                        //   int r =m-1;
                        //   int maximum=0;
                        //   int maxindex=0;
                        //   while (l<=r){
                               
                        //        int mid = l+(r-l)/2;
                               
                        //        if ((mid-1>=0) && mat[i][mid-1]<=mat[i][mid]){
                        //                maxindex=mid;
                        //               r=mid-1;
                        //        }
                        //        else{
                        //          l=mid+1;
                        //        }

                                 
                        //   }

                        //   cout<<mat[i][maxindex]<<endl;


                        // up element 
                        //  
                        if (i-1>0 && mat[i-1][maxindex]>mat[i][maxindex]){
                                continue;
                        }
                        if (i+1<n && mat[i+1][maxindex]>mat[i][maxindex]){
                                continue;
                        }

                       else  {return {i,maxindex};}
                  }

                  return ans;


    }
};