class Solution {
public:
    int n,m;
    int original =0;
    void solve(vector<vector<int>>& image, int sr, int sc, int color){
          
            if (sr>=n || sc>=m || sr<0 || sc<0 || image[sr][sc]!=original){
                 return ;
            }

            image[sr][sc]= color;            
             
           solve(image, sr+1,sc,color);
           solve(image, sr-1,sc,color);
           solve(image, sr,sc+1,color);
           solve(image, sr,sc-1,color);

    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
         n=image.size();
         m=image[0].size();
         original = image[sr][sc];
        if (original== color) {
            return image;
        }
          
         solve(image,sr,sc, color);

         return image;








    }
};