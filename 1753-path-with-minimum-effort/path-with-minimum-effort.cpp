class Solution {
public:
  int n,m;
    typedef pair<int ,pair<int,int>> p;
    vector<int>dx= {-1,0,0,1};
    vector<int>dy= {0,-1,1,0};

    int minimumEffortPath(vector<vector<int>>& heights) {
         n = heights.size();
         m = heights[0].size();
            auto ispos = [&](int x, int y){
                return x>=0 && x<n && y>=0 && y<m;
                };
         vector<vector<int>>result(n,vector<int>(m,INT_MAX));
         priority_queue<p,vector<p>, greater<p>> pq;

         pq.push({0,{0,0}});
         result[0][0]=0;
         
        while (!pq.empty()){
              
               auto top = pq.top();
               pq.pop();
               int diff = top.first;
               auto p = top.second;
               int x = p.first;
               int y = p.second;
              
               for(int i=0;i<4;i++){
                     int currx = x+dx[i];
                     int curry = y+dy[i];
                      
                     if (ispos(currx,curry)){
                            
                            int absdiff = abs(heights[x][y] -heights[currx][curry] );
                            int maxdiff = max(diff , absdiff);
                            if (maxdiff<result[currx][curry]){
                                     result[currx][curry] = maxdiff;
                                     pq.push({maxdiff , {currx, curry}});
                            }

                     } 
               }

             
        }
  return result [n-1][m-1];
    }
};