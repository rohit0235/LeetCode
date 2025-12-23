class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
         
         int n = events.size();
         sort(events.begin(),events.end());
         vector<int>maxii(n,INT_MAX);
         maxii[n-1] = events[n-1][2];
         for(int i=n-2;i>=0;i--){
             maxii[i] = max(events[i][2],maxii[i+1]);
         }
        //  for(int i:maxii)cout<<i<<" ";
        //  cout<<endl;
         int maxi = INT_MIN;
         for(int i=0;i<n;i++){
               int val = events[i][1];

               int l = i+1;
               int r =n-1;
               int ans = -1;

               while (l<=r){
                    int mid = (l+r)/2;
                    // cout<<events[mid][0]<<" "<<val<<endl;
                    if (events[mid][0]>val){
                          ans = mid;
                          r=mid-1;
                    }
                    else{
                         l = mid+1;
                    }
               }
                //  cout<<ans<<" "<<val<<endl;
                // cout<<val<<endl;
               if (ans!=-1){
                // cout<<events[i][2]<<" "<<maxii[ans];
                   maxi = max(maxi , events[i][2]+maxii[ans]);
               }
               else{
                     maxi = max(maxi , events[i][2]);
               }
               
               
         }

         return maxi;

    }
};