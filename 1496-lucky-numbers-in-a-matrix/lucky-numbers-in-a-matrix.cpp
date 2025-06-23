class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
          
           int n =matrix.size();
           int m =matrix[0].size();

           vector<int>r(max(n,m),INT_MAX);
           vector<int>ans;
           for(int i=0;i<n;i++){
                 
                  int mini =INT_MAX;
                 for(int j=0;j<m;j++){
                     mini=min(mini,matrix[i][j]);
                 }

                 r[i]=mini;
           }

           for(int i:r) cout<<i<<endl;
           for(int i=0;i<m;i++){
                 
                  int maxi =INT_MIN;
                  int maxindex=0;
                 for(int j=0;j<n;j++){
                    if (maxi<matrix[j][i]){
                            maxi =matrix[j][i];
                            maxindex=j;
                        }
                 }

                 if (r[maxindex]==maxi) {
                     ans.push_back(maxi);
                 }
           }
          return ans;
          
    }
};