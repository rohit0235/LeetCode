class Solution {
public:
    int minimumRecolors(string blocks, int k) {

         int white=0;                
         int n=blocks.size();
         for(int i=0;i<k;i++){
              if (blocks[i]=='W') white++;
         }

         int mini=white;

         for(int i=k;i<n;i++){
                 if (blocks[i-k]=='W') white--;
                 if (blocks[i]=='W') white++;
                 mini=min(mini,white); 
         }

         return mini;
    }
};