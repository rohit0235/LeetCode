class Solution {
public:
       int n ,m;
    void solve(vector<bool>&visited , vector<vector<int>>& rooms , int i){

           visited[i] = true;

           for(auto j:rooms[i]){
                    if (!visited[j]){
                         solve(visited , rooms , j);
                    }
           }   
        
    }
   
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
            n = rooms.size();
        m = rooms[0].size();

            vector<bool>visited(n,false);
            visited[0] = true;
            for(int i:rooms[0]){
                  if (visited[i]==false){
                       solve(visited , rooms  , i);
                  }
            }

            for(bool i:visited){
                  if (!i){
                      return false;
                  }
            }

            return true;
    }
};