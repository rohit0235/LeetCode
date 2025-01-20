class Solution {
public:
    int largestAltitude(vector<int>& gain) {
         
   
       int maxle=0;
       int n=gain.size();
         for (int i=0;i<n;i++){
            if (i==0) gain[i]=gain[i]+0;
            else gain[i]=gain[i-1]+gain[i];
             maxle=max(maxle,gain[i]);
        }

        return maxle;
    }
};