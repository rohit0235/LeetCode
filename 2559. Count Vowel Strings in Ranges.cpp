class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
               
               vector<int >co;
               vector<int>store;
for (string i:words){
        int n =i.size();
     if ((i[0]=='a' || i[0]=='e' || i[0]=='i' || i[0]=='o' || i[0]=='u')&& (i[n-1]=='a' || i[n-1]=='e' || i[n-1]=='i' || i[n-1]=='o' || i[n-1]=='u')){
             store.push_back(1);
     }
        else{
        store.push_back(0);
        }
           }
          vector<int> prefixSum(store.size() + 1, 0);
    for (size_t i = 0; i < store.size(); ++i) {
        prefixSum[i + 1] = prefixSum[i] + store[i];
    }


    for (const auto& query : queries) {
        int l = query[0], r = query[1];
        co.push_back(prefixSum[r + 1] - prefixSum[l]);
    }

    return co;
    }
};
