class Solution {
public:

   
    vector<int> findSubstring(string s, vector<string>& words) {
           
             vector<int>res;
           
             unordered_map<string,int>mp;
             for(auto i:words) mp[i]++;
             
              int n =words.size();
              int m =words[0].size(); 
                if (s.size()<n*m) return {};
                    int     k=n*m;
             for(int i=0;i<=s.size()-k;i++){
                   // if i is 0 then j will rum till 5  
                   unordered_map<string,int>check;
                 
                    for(int j=i;j<i+k;j+=m){
                         
                         string c=  s.substr(j,m);
                        //  cout<<c<<endl;
                        //  if (check[c]>mp[c] || mp.find(c)==mp.end()){
                        //      break;
                        //  }
                         
                         check[c]++;

                    }
                    // cout<<check.size()<<" "<<n<<endl;

                    if (check==mp){
                         res.push_back(i);
                    }

             }

             return res;
 

    }
};