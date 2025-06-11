class Solution {
public:
    string convert(string s, int numRows) {
          // 1  5  9 13 
          // 2 4 6 8 10 
          // 3  7 11 

        int n=s.size();
        int z = numRows-1;
        vector<string>ans(n);

        int j=0;
        while (j<n){
              
                   for(int i=0;i<numRows;i++){

                         if (j>=n) break;
                         ans[i].push_back(s[j]);
                         j++;
                   }
                   
                   for(int k=z;k>1;k--){
                          if (j>=n) break;
                          ans[k-1].push_back(s[j]);
                          j++;
                   }

        }
         

        //  for(string i:ans) cout<<i<<" ";
         string an ="";
         for(string i:ans){
             an=an+i;
         }
         return an;

    }
};