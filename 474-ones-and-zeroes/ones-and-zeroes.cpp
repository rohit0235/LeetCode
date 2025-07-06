class Solution {
public:

// static bool cmp(string &a, string &b ){
//       return a.size()<b.size();
// }

int dp[101][101][601];

int solve( int ze , int on , vector<pair<int,int>>&v , int i){
         
            if (i>=v.size()) return 0;
                 
            //  if (ze<0 || on<0) return 0;
            if (dp[ze][on][i]!=-1) return dp[ze][on][i];
               
             int remm = v[i].first;
             int  remn = v[i].second;
             int first  = -1;

             if (remm<=ze && remn<=on){
                 
                  first = 1+solve(ze-remm, on-remn, v, i+1);
             }
             int second = solve(ze , on , v , i+1);
           
         
          
            // int second = solve(m,n,ze, on, v, i+1);

            return dp[ze][on][i]=max(first , second);
        
}
    int findMaxForm(vector<string>& strs, int m, int n) {
              memset(dp,-1 ,sizeof(dp));

        vector<pair<int,int>>v;

        for(string i:strs){
                int z=0;
                int o=0;
               for(auto j:i){
                 
                   if (j=='0') z++;
                   else o++;
               }
               v.push_back({z,o});
        }

        return solve( m , n,v,0);
             
            // //  sort(strs.begin(),strs.end(),cmp);
            // // 2 4  
            //     int ans =0;
            //     int z=0;
            //      int o=0;
            //  for(auto i:strs){
                                        
            //          if (m+n<i.size()){
            //          continue;
            //          }
            //          int currentz=0;
            //          int curro=0;
                 
            //          for(int j=0;j<i.size();j++){
            //               if (z>m || o>n) break;
            //               if (i[0]=='0') currentz++;
            //               else curro++;
                          
            //          }

            //          if (z+currentz<=m && o+curro<=n) {
            //              z+=currentz;
            //              o+=curro;
            //               ans++;
            //          }
                   

            //  }
            //    return ans;              
             
    }
};