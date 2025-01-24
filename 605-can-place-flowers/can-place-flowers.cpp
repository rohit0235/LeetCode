class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int &n) {
          int p = flowerbed.size();
        int count = 0;  // Count of flowers planted
        
        for (int i = 0; i < p; ++i) {
            // Check if the current slot is empty and its neighbors are also empty or out of bounds
            if (flowerbed[i] == 0 && 
                (i == 0 || flowerbed[i - 1] == 0) && 
                (i == p - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;  // Plant a flower here
                count++;
                
                if (count >= n) return true;  // Early exit if we reach the required count
                
                i++;  // Skip the next slot since we can't plant adjacent flowers
            }
        }
        
        return count >= n;  // Check if we could plant enough flowers












        //  int finals=n;
        // if (p==1 && flowerbed[0]==0 ) return true;
        //  for (int i=0;i<p;i++){
        //     if (n<=0) return true;
        //        if (i==0){
        //              if (flowerbed[i]==0 && flowerbed[i+1]==0) {

        //                 n--;
        //                 flowerbed[i]=1;
        //              }
        //        }
        //       else  if (i==p-1)  {
        //        if (flowerbed[i-1]==0 && flowerbed[i]==0  ) {
        //                 n--;
        //                    cout<<i<<" ";
        //                 flowerbed[i]=1;
        //              }
        //        }
        //        else if (flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
        //                      n--;
                          
        //                      flowerbed[i]=1;
        //        }
        //  }
        //      if (n<=0) return true;
        //  return false;
         

    }
};