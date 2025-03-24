class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
           int n=meetings.size();
           
           sort(meetings.begin(),meetings.end());

           int diff=0;
           int maxend=meetings[0][1];
           for(int i=1;i<n;i++){
                
                if (maxend<meetings[i][0]){
                    diff+=meetings[i][0]-maxend-1;
                   
                }
                 maxend = max(maxend, meetings[i][1]);
           }
            // cout<<diff<<" "<<endl;
           diff+=meetings[0][0]-1;
           diff+=days-maxend;
           
           return diff;


        //    vector<int>s(days+1,0);
        //    // 0 0 0 0 0 0  // 0 1 0 0 -1 0  // 1 1 0 -2 0 0 // 1 2 2 0 0
        //    for (int i=0;i<n;i++){
                   
        //           s[meetings[i][0]-1]++;  
        //           s[meetings[i][1]]--;

        //    }

        //    for(int i=1;i<days;i++){
        //          s[i]+=s[i-1];
        //    }

        //    int count=0;
        //    for(int i=0;i<days;i++){
        //         if (s[i]==0) count++;
        //    }

        //    return count;
    }
};