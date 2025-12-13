class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<pair<string ,string >,bool>>p;
        for(int i=0;i<isActive.size();i++){
             p.push_back({{businessLine[i],code[i] },isActive[i]});
        }

        sort(p.begin(),p.end());

        vector<string>ans;
        for(auto i:p){
              
               string f = i.first.first;
               string s = i.first.second;
               bool act = i.second;

               if (s=="") continue;
               bool flag = true;
               for(char i:s){
                  if (!isalnum(i) && i!='_') flag = false;
               }
               if (!flag ) continue;
             
               if (act==false) continue;

               if (f=="electronics" || f=="grocery" || f=="pharmacy" || f=="restaurant"){
                  ans.push_back(s);
               }


        }
        return ans;

    }
};