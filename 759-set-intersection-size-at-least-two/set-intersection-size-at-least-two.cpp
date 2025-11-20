class Solution {
public:
static  bool cmp(vector<int>&a, vector<int>&b){
      if (a[1]==b[1]){
          return a[0]>b[0];
      }
      return a[1]<b[1];
}
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
          
           int n = intervals.size();

           sort(intervals.begin(),intervals.end(),cmp);
        //    for(auto i:intervals) cout<<i[0]<<" "<<i[1]<<endl;
           int ans =2;
           int prev2 = intervals[0][1]-1;
           int prev1 = intervals[0][1];
           for(int i=1;i<n;i++){
                     if (intervals[i][0]>prev1){
                          ans+=2;
                          prev1= intervals[i][1];
                          prev2= intervals[i][1]-1;
                      }
                      else if (intervals[i][0]>prev2){
                          ans+=1;   
                          prev2= prev1;
                          prev1= intervals[i][1];
                      
                      }
              
           }
          return ans;
    }
};