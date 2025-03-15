class Solution {
public:
    int maxArea(vector<int>& height) {
          
          int n =height.size();
          
          //    1 8 6 2 5 4 8 3 7
          int maxarea=0;
          int l=0;
          int r=n-1;
          while(l<=r){
               int check=min(height[l],height[r]);
               maxarea=max(maxarea,check*(r-l));
               if(height[l]<=height[r]) l++;
               else r--;  
          }
          return maxarea;




 













        //   int l=0;
        //   int r=n-1;
        //   int maxi=0;
        //   while (l<r){
                  
        //         int h=min(height[l],height[r]);
        //         int w=r-l;
        //         maxi=max(maxi,h*w);

        //         if (height[l]<height[r]) {
        //             l++;
        //         }
        //         else{
        //             r--;
        //         }

        //   }
         
        //  return maxi;




        //   int l=0;
        //   int r=n-1;
        //   int maxi=0;
        //   while (l<r){
        //       int h=min(height[l],height[r]);
        //       int w=r-l;
        //       maxi=max(maxi,h*w);

        //      height[l]<height[r] ? l++ : r--;
        //   }

        //   return maxi;








    }
};