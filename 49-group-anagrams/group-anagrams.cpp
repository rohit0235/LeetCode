class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {                     unordered_map<string,vector<string>>result;
                 int n=strs.size();
           for(string i:strs){
                 
                   vector<int>chars(26,0);

                   for(char s:i){
                        chars[s-'a']++;
                   }
                  string key="";
                   for(int i=0;i<26 ;i++){
                        key+=to_string(chars[i])+"#";
                   }
                result[key].push_back(i);
           }
            vector<vector<string>>res;
           for(auto i:result){
                 res.push_back(i.second);
           }

           return res;





            //    vector<vector<string>> res;
            //    unordered_map<string,int>mp;
            //     int n=strs.size();
            //     int j=0;
            //    for(int i=0;i<n;i++){
                    
            //          string fin=strs[i];

            //          sort(strs[i].begin(),strs[i].end());
            //         //  for(auto i:mp){
            //         //      cout<<i.first<<" "<<i.second<<" ";

            //         //  }
            //         //  cout<<endl;
            //          if (mp.find(strs[i])!=mp.end()){
            //             int index=mp[strs[i]];
            //             //   cout<<index<<" "<<endl;
            //               res[index].push_back(fin);
            //          }
            //          else{
            //               res.push_back({fin}); 
            //                mp[strs[i]]=j;
            //                j++;
            //          }

                   
            //    }

            //    return res;
    }
};