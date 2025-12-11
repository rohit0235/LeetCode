class Solution {
public:
 static bool cmp(vector<int>&a, vector<int>&b){
    if (a[1]==b[1]){
         return a[0]>b[0];
    }
         return a[1]<b[1];
 }
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<pair<int,int>, int>mp;
         int k = buildings.size();
         sort(buildings.begin(),buildings.end());
         for(int i=1;i<k-1;i++){
                    if (buildings[i-1][0]==buildings[i][0] && buildings[i+1][0]==buildings[i][0]){
                         mp[{buildings[i][0],buildings[i][1]}]++;
                    }
         }
               sort(buildings.begin(),buildings.end(),cmp);
            //    for(auto i:mp){
            //       cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
            //    }
               int ans =0;
         for(int i=1;i<k-1;i++){
                    if (buildings[i-1][1]==buildings[i][1] && buildings[i+1][1]==buildings[i][1]){  
                        //  cout<<buildings[i][0] <<" "<<buildings[i][1]<<endl; 
                            if (mp.count({buildings[i][0] ,buildings[i][1] })){
                                 ans++;
                            }
                    }
         }
         return ans;

        
    }
};