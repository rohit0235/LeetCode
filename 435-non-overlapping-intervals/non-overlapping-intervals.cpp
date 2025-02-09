class Solution {
public:

    static    bool cmp(vector<int>&a,vector<int>&b){
             return a[1]<b[1];
        }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
               int n =intervals.size();
           sort(intervals.begin(),intervals.end(),cmp);
   
            int laste=intervals[0][1];
        
            int cnt=1;
            for (int i=1;i<n;i++){
                 
                 if (laste <=intervals[i][0]){
                    cnt++; laste=intervals[i][1];
                 } 
           
            }

            return n-cnt;


    }
};