class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hb, vector<int>& vb) {
        //  vector<int>hwala;

        const int MOD = 1e9 + 7;
        hb.push_back(1);
        hb.push_back(m);
        vb.push_back(1);
        vb.push_back(n);
        sort(hb.begin(), hb.end());
        sort(vb.begin(), vb.end());
        unordered_map<int, int> mp;
        //  unordered_map<int,int>mp2;

        //  for(auto i:hb)mp[i]++;

        int maxarea = -1;

        for (int i = 0; i < vb.size(); i++) {

            for (int j = i + 1; j < vb.size(); j++) {

                int diff = abs(vb[j] - vb[i]);
                mp[diff]++;
            }
        }
        for (int i = 0; i < hb.size(); i++) {

            for (int j = i + 1; j < hb.size(); j++) {

                int diff = abs(hb[j] - hb[i]);

                if (mp.count(diff)) {
                    // long long area = 1LL * diff * diff;
                    maxarea = max(maxarea,diff);
                }
            }
        }
if (maxarea == -1) return -1;
return (1LL * maxarea * maxarea) % MOD;


        //  int mini =INT_MAX;
        //  int maxi =-1;

        //  for(auto i:mp){
        //      if(i.second%2==0){
        //           mini = min(mini,i.first);
        //           maxi = max(maxi,i.first);
        //      }
        //  }

        //   cout<<maxi << " "<<mini<<endl;
        //  if(maxi==-1 || mini == INT_MAX || mini == maxi) return -1;

        //  return (maxi-mini)*(maxi-mini);
        // 1 2 3
        // 1 2 3 4

        //  suppsoe we have taken the 1-2
        //

        // bat ye hai ki
        //  int maxh = 1;
        //  int maxcount =1;
        //  for(int i=1;i<hb.size();i++){
        //        if(hb[i]-hb[i-1]==1){
        //           maxcount++;
        //        }
        //        else{
        //          maxcount=1;
        //        }

        //        maxh = max(maxh , maxcount);
        //  }
        //  int maxv = 1;
        //  maxcount =1;
        //  for(int i=1;i<vb.size();i++){
        //        if(vb[i]-vb[i-1]==1){
        //           maxcount++;
        //        }
        //        else{
        //          maxcount=1;
        //        }

        //        maxv = max(maxv , maxcount);
        //  }

        // return  min (maxh+1,maxv+1)*min (maxh+1,maxv+1);
    }
};