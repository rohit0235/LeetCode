class Solution {
    // array that works as map to keep track of parent nodes and size of islands
    int par[250005], sz[250005];

    // hashing function for map
    int getId(int i, int j, int m) {
        return i*m + j;
    }

    void dsuDfs(vector<vector<int>>& grid, int i, int j) {
        int dx[] = {1, -1, 0, 0},
            dy[] = {0, 0, 1, -1};

        for(int a=0; a<4; a++) {
            int x = i + dx[a],
                y = j + dy[a];

            int id_orig = getId(i, j, grid.size()),
                id_new = getId(x, y, grid.size());

            // we check if the node exists
            // if the node is an island
            // and if the node is not already traversed by comparing parents
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() 
            && grid[x][y] && par[id_new] != par[id_orig]) {
                // get the parent ids
                id_orig = par[id_orig];
                id_new = par[id_new];
                
                // set the new parent and modify size
                par[id_new] = par[id_orig];
                sz[id_orig] += sz[id_new];
                dsuDfs(grid, x, y);
            }
        }
    }

    void buildDsu(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // initialize the dsu
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int id = getId(i, j, m);

                // set the parent to itself
                par[id] = id;

                // set the size to 1/0
                sz[id] = grid[i][j];
            }
        }

        // create the sets
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int id = getId(i, j, m);
                if(grid[i][j] && par[id] == id) {
                    dsuDfs(grid, i, j);
                }
            }
        }
    }

    int maxAns(vector<vector<int>>& grid, int i, int j) {
        int dx[] = {1, -1, 0, 0},
            dy[] = {0, 0, 1, -1};

        set<int> parents;

        // add all the adjacent nodes to set
        for(int k=0; k<4; k++) {
            int x = i + dx[k],
                y = j + dy[k];

            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() 
            && grid[x][y]) {

                int id = getId(x, y, grid.size());
                parents.insert(par[id]);
            }
        }

        int ans = 1;
        for(int parent: parents) {
            ans += sz[parent];
        }

        return ans;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        buildDsu(grid);

        int m = grid.size(), n = grid[0].size(), ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int id = getId(i, j, m);
                
                if(!grid[i][j]) {
                    ans = max(
                        ans,
                        maxAns(grid, i, j)
                    );
                } else {
                    ans = max(
                        ans,
                        sz[id]
                    );
                }
            }
        }

        return ans;
    }
};