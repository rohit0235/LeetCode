class Solution {
public:
     
     int t[103][103];
    int solve(vector<int>&cuts ,  int n , int l , int r){
         
            if (r-l<2) return 0;
            int result = INT_MAX;
            if (t[l][r]!=-1) return t[l][r];
            for(int i = l+1;i<=r-1;i++){ 
                 int cost = (cuts [r]- cuts[l]) +  solve(cuts , n ,l , i ) + solve(cuts , n , i , r);     
            
             result = min(result , cost);
            }         

            return t[l][r]=result;  


 
           
    }

    int minCost(int n, vector<int>& cuts) {
            
        //    vector<vector<int>>dp(n,vector<int>(n,0)) ;
          memset(t,-1,sizeof(t));
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);

        cuts.push_back(n);

        return solve(cuts , n , 0 , cuts.size()-1);

             

              
               
    }
};