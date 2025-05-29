class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {

      
            int m=matrix.size();
            int n = matrix[0].size();
            int l =0;
            int r =m-1;
            int ans=0;
            while (l<=r){
                    
           int mid=(l+(r-l)/2);
                if (matrix[mid][0]==x) return true;
                if (matrix[mid][0]<x){
                     ans = mid;
                     l=mid+1;
                }
               else  if (matrix[mid][0]>x) {
                       r=mid-1;
                }
               

            }  
            // cout<<ans<<" ";
            l = 0;
            r=n-1;

            while (l<=r){
                         
                  int mid=(l+(r-l)/2);
                //   cout<<matrix[ans][mid]<<endl;
                //   cout<<mid<<endl;
                if (matrix[ans][mid]==x) return true;
              else   if (matrix[ans][mid]<x){
                     l=mid+1;
                }
               else  if (matrix[ans][mid]>x) {
                       r=mid-1;
                }
               


            }
         
              return false;

    }
};