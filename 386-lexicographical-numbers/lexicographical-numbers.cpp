class Solution {
public:
    vector<int> lexicalOrder(int n) {
            // vector<int>ans;
            // for(int i=1;i<10 && i<=n ;i++){
            //         ans.push_back(i);  

            //         int j =i*log2(n);

            //         while (j<n && j<n){
                            
            //                 for(int k = j;k<=n;k++){
            //                      ans.push_back(k);

            //                 }

            //                 j=j/10;

            //         }

                         
            // }

            // return ans;

            vector<string>ans;

            for(int i=1;i<=n;i++){
                 ans.push_back(to_string(i));
            }
            sort(ans.begin(),ans.end());
                      vector<int>ans2;

                      for(string i:ans){
                           ans2.push_back(stoi(i));
                      }
            return ans2 ;

    }
};