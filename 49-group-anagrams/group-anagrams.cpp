class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
           
               vector<vector<string>> res;
               unordered_map<string,int>mp;
                int n=strs.size();
                int j=0;
               for(int i=0;i<n;i++){
                    
                     string fin=strs[i];

                     sort(strs[i].begin(),strs[i].end());
                    //  for(auto i:mp){
                    //      cout<<i.first<<" "<<i.second<<" ";

                    //  }
                    //  cout<<endl;
                     if (mp.find(strs[i])!=mp.end()){
                        int index=mp[strs[i]];
                        //   cout<<index<<" "<<endl;
                          res[index].push_back(fin);
                     }
                     else{
                          res.push_back({fin}); 
                           mp[strs[i]]=j;
                           j++;
                     }

                   
               }

               return res;
    }
};