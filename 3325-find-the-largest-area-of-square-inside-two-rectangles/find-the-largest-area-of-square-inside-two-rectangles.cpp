class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl,
                                vector<vector<int>>& tr) {

        int side = 0;

        vector<vector<int>> h;
        vector<vector<int>> v;
        // vector<pair<int ,int> >v;

        for (int i = 0; i < bl.size(); i++) {

            h.push_back({bl[i][0], tr[i][0]});
            v.push_back({bl[i][1], tr[i][1]});
        }

        for (int i = 0; i < bl.size() - 1; i++) {

            // int maxh = h[i][0];
            // int minh = h[i][1];
            // int maxv = v[i][0];
            // int minv = v[i][1];
            //  cout<<maxh<<" "<<minh<<" ";
            for (int j = i + 1; j < bl.size(); j++) {
                int maxh = max(h[i][0], h[j][0]);
                int minh = min(h[i][1], h[j][1]);

                int maxv = max(v[i][0], v[j][0]);
                int minv = min(v[i][1], v[j][1]);

                //  cout<<maxh<<" "<<minh<<" "<<endl;;
                //  cout<<maxv<<" "<<minv<<" "<<endl;;
                //  cout<<endl;

                int overlapX = minh - maxh; 
                int overlapY = minv - maxv; 

                int currSide = min(overlapX, overlapY);
                if (currSide > 0)
                    side = max(side, currSide);
            }
        }

        return 1LL * side * side;
    }
};