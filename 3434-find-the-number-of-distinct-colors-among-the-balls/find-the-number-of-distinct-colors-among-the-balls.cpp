class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
              
              int n=queries.size();
              vector<int>ans;
              
               unordered_map<int,int>color;
               unordered_map<int,int>ballmap;
  
                for (int i=0;i<n;i++){


                         int ball=queries[i][0];
                         int col=queries[i][1];

                         if (ballmap.count(ball)){
                             int prev=ballmap[ball];
                              color[prev]--;
                              
                              if (color[prev]==0) color.erase(prev);
                         }


                         ballmap[ball] =col;
                         color[col]++;

                         ans.push_back(color.size());

                }

                return ans;

         
              
            
    }
};