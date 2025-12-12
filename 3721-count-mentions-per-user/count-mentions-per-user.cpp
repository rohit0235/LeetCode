class Solution {
public:
 unordered_map<string ,string>mp;
int all =0;
 void solve(vector<int>&ans , vector<vector<string>>& events,vector<string>& i,int numberOfUsers){
           
           if (i[2]=="ALL"){
                  all++;
           }
           else if (i[2]=="HERE"){

                  for(int k=0;k< numberOfUsers;k++){
                        string key = to_string(k);
                        //    cout<<key;
                        if (mp.count(key)){
                                    // cout<<key<<endl;
                                   int time = stoi(mp[key]);
                                   int g = stoi(i[1]);
                                //    cout<<time<<" "<<g;
                                   if (time+60<=g){
                                         ans[k] ++;
                                   }

                        }
                        else{
                         
                              ans[k] ++;
                        }
                  }  
                 
           }
           else{
                  
                 string allid = i[2];
                 
                 int num =0;
                 bool flag =false;
                 for(char j:allid){
                      if (j=='d'){
                          flag = true;
                      }
                      else if (j==' '){  
                           flag = false;
                        //    cout<<num<<endl;
                           ans[num]++;
                           num=0;
                      }
                      else   if (flag){
                          num = num*10+(j-'0');
                      }
                 }
                //  cout<<num<<endl;
                 ans[num]++;
           }
  

 }
 static bool cmp(vector<string>&a , vector<string>&b){
     int m,n;
     m = stoi(a[1]);
     n = stoi(b[1]);
    if (m==n){
         return a[0]>b[0];
    }
     return m<n;
 }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
     
        int n = events.size();
        vector<int>ans(numberOfUsers,0);
        sort(events.begin(),events.end(),cmp);
        
        // for(int i=0;i<numberOfUsers;i++){
        //       string key = to_string(i);
        //       mp[key] = events[0][1];
        // }  
         mp.clear();
        for(auto i:events){
              cout<<i[1]<<endl;
              if (i[0]=="MESSAGE"){
                solve(ans , events, i, numberOfUsers);
              }
              else if (i[0]=="OFFLINE"){
                  string id = i[2];
                  mp[id]=i[1];
                  
              }
              
        }
        for(int i=0;i<ans.size();i++){
             ans[i] = ans[i]+all;
        }

        return ans;

    }
};