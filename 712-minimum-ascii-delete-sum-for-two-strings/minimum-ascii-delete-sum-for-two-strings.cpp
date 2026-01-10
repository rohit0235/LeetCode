class Solution {
public:
    
    int n,m;
    int t[1001][1001];
 
    int solve(string& s1, string& s2, int i, int j){
          if(i==n && j==m) return 0;
           if(i>=n){
               int sum =0;
               while(j<m){
                  sum+=s2[j];
                  j++;
               }

               return sum;
           }
           if(j>=m){
               int sum =0;
               while(i<n){
                  sum+=s1[i];
                  i++;
               }

               return sum;
           }
           if(t[i][j]!=-1) return t[i][j];
        //   int first =0;
           if(s1[i]==s2[j]){
             return solve(s1,s2,i+1,j+1);
           }
           int second = s1[i]+ solve(s1,s2,i+1,j);
           int third =  s2[j]+solve(s1,s2,i,j+1);
            // cout<<second<<" "<<third<<endl;
          return t[i][j]=min(second,third);
          
    }
  
    int minimumDeleteSum(string s1, string s2) {
        n=s1.size();
        m=s2.size();

        memset(t,-1,sizeof(t));
        return solve(s1,s2, 0,0);
    }
};