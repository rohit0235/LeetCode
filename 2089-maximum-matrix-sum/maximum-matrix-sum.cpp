class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
         long long n = matrix.size();
         long long m = matrix[0].size();

         long long sum =0;
         long long mini = LLONG_MAX;
             long long c =0;
        for( long long i=0;i<n;i++){
              for( long long j=0;j<m;j++){
                   if(matrix[i][j]<0) c++;
                   if(mini>abs(matrix[i][j]))
                   mini =  abs(matrix[i][j]);
                   sum+=abs(matrix[i][j]);
              }
        }

        if(c%2==0) return sum;

        return sum-=2*mini;
    }
};