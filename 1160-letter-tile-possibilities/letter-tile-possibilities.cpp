class Solution {
public:
      int n;
     void solve(string &curr, unordered_set<string>&result,vector<bool>&used,string tiles){
           
            result.insert(curr);

       

           for (int i=0;i<n;i++){
                    if (used[i]) continue;
                    used[i]=true;
                 curr.push_back(tiles[i]);
                 solve(curr,result,used,tiles);
                 
                  used[i]=false;
                 curr.pop_back();
           }
            
     }
    int numTilePossibilities(string tiles) {
             n =tiles.size();

           vector<bool>used(n,false);

           unordered_set<string>result;
           string curr="";
           solve (curr,result,used,tiles);

           return result.size()-1;
            

    }
};