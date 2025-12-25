class Solution {
public:
         int t[101][101];
        int ans (int i, int j){
                if (i==0 && j==0 ) return 1;
         
                if (j<0 || i<0) return 0;
                 if (t[i][j]!=-1) return t[i][j];
                return t[i][j]= ans(i-1,j)+ans(i,j-1);
        }
    int uniquePaths(int m, int n) {
      memset(t,-1,sizeof(t));
      return ans(m-1,n-1);

                  
    }
};