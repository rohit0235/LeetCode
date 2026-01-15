class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hb, vector<int>& vb) {
         vector<int>hwala;
         sort(hb.begin(),hb.end());
         sort(vb.begin(),vb.end());

         int maxh = 1;
         int maxcount =1;
         for(int i=1;i<hb.size();i++){
               if(hb[i]-hb[i-1]==1){
                  maxcount++;
               }
               else{
                 maxcount=1;
               }

               maxh = max(maxh , maxcount);
         }
         int maxv = 1;
         maxcount =1;
         for(int i=1;i<vb.size();i++){
               if(vb[i]-vb[i-1]==1){
                  maxcount++;
               }
               else{
                 maxcount=1;
               }

               maxv = max(maxv , maxcount);
         }


        return  min (maxh+1,maxv+1)*min (maxh+1,maxv+1);

         
    //      int j=0;
    //      for(int i=1;i<=n+2;i++){
    //         // cout<<i<<" "<<j<<endl;
    //            if(j<hb.size() && i==hb[j]){
    //                j++;
    //            }
    //            else{
    //                 hwala.push_back(i);
    //            }
    //      }
    //      vector<int>vwala;
        
    //      j=0;
    //      for(int i=1;i<=m+2;i++){
    //            if(j<vBars.size() && i==vBars[j]){
    //                j++;
    //            }
    //            else{
    //                 vwala.push_back(i);
    //            }
    //      }

    //     //  // ab hame dono ki height mil gayi 
    // //    for(int i:vwala)cout<<i<<endl;
    // //    for(int i:hwala)cout<<i<<endl;
    //     int ans =0;
    //      for(int i=0;i<min(hwala.size(),vwala.size())-1;i++){
    //             //  cout<<hwala[i]<<" "<<vwala[i]<<endl;
    //              int hdiff = min(hwala[i+1],vwala[i+1]) - min(hwala[i],vwala[i]);
    //             //  int vdiff = vwala[i+1]-vwala[i]-1;
    //             //  cout<<hdiff<<endl;
    //               int area = hdiff* hdiff;
    //              ans = max(ans , area);
                
    //      }
    //      return ans;
    }
};