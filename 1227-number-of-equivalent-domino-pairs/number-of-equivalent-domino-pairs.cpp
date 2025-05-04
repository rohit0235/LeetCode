class Solution {
public:
    // struct pair_hash {
    //     size_t operator()(const pair<int, int>& p) const {
    //         return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    //     }
    // };
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

              int n=dominoes.size();
             
            map<pair<int, int>, int> mp;
             int ans=0;
              for(auto i:dominoes){
                   
                     int a=i[0];
                     int b=i[1];
                     if (a>b) swap(a,b);
                     pair<int,int>check=make_pair(a,b);
        
            

                    mp[check]++;

              }  
              for(auto i:mp){
                   
                   int freq=i.second;
                   ans+=((freq)*(freq-1))/2;
              }  

              return ans;
              





            //    int ans=0;
            //   for(int i=0;i<n;i++){
                 
            //       for(int j=i+1;j<n;j++){
                             
            //              int a=dominoes[i][0];
            //              int b=dominoes[i][1];
            //              int c=dominoes[j][0];
            //              int d=dominoes[j][1];
                         
            //              if ((a==c &&  b==d) || (a==d && b==c)) {
            //                   ans++;
            //              }
                       

            //       }
            //   }   

            //   return ans;
              

    }
};