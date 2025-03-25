class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end());
          vector<vector<int>>result;
          int n=intervals.size();
          int i=0;
          while (i<n){
                  int start=intervals[i][0];
                  int j=i+1;
                  int end=intervals[i][1];
                  while (j<n && end>=intervals[j][0]){
                        end=max(end,intervals[j][1]);
                        j++;
                  }
                  result.push_back({start,end});
                  i=j;
                  
          }

          return result;

    }
};