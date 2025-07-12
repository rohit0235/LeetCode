class Solution {
public:

vector<vector<string>> res;

bool ispal(string &s , int l , int r){
          
            while (l<=r){
                 
                  if (s[l]!=s[r]) return false;
                       l++;
                       r--;
            }

            return true;
             
      
}

void solve(string s , int idx , vector<string>&curr){
     
         if (idx>=s.size()) {
             res.push_back(curr);
             return ;
         }


         for(int i=idx;i<s.size();i++){
              
                  if (ispal(s,idx,i)){
                      
                         curr.push_back(s.substr(idx,i-idx+1));
                         solve(s,i+1,curr);
                        curr.pop_back();
                      
                  }
              
               
         }


         
       
         
}
    vector<vector<string>> partition(string s) {
               
               vector<string>curr;

               solve(s,0,curr);

               return res;

    }
};