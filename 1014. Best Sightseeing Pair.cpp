class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
             
                   int n =values.size();
                    int maxi=INT_MIN;

                    for (int i=0;i<n;i++){
                              values[i]=values[i]+i;
                    }
                    int jmax=values[n-1]-2*(n-1);

                    for (int j=n-2;j>=0;j--){
                         jmax=max(jmax,values[j+1]-j-1-j-1);   
                         maxi=max(maxi,values[j]+jmax);
                       
                    }

                    return maxi;

    }
};
