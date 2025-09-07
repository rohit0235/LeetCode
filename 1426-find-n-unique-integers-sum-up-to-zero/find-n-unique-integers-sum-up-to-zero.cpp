class Solution {
public:
    vector<int> sumZero(int n) {
             
             int i=1;
             int j=-1;
             if (n==1) return {0};
             vector<int>ans;
             for(int k=0;k<n/2;k++){
                  ans.push_back(i);
                  ans.push_back(j);
                  i++;
                  j--;

             }

             if (n%2==1) ans.push_back(0);
             return ans;
    }
};