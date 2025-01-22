class Solution {
public:
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2); // Combine hashes
        }
        return seed;
    }
};
    int equalPairs(vector<vector<int>>& grid) {
        
        int count=0;
        unordered_map<std::vector<int>, int, VectorHash> mp;
        for (auto i:grid) mp[i]++; 

        for (int i=0;i<grid[0].size();i++){
            vector<int>temp;
            for(int j=0;j<grid.size();j++){
                 temp.push_back(grid[j][i]);
            }

                count+=mp[temp]; 

            
        }

        return count;
    }
};