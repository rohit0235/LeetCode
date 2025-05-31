class Solution {
public:
    int trap(vector<int>& height) {

           int n=height.size();
           
           vector<int>rm(n,0);
           rm[n-1] = height[n-1];

           for(int i=n-2;i>=0;i--){
              rm[i]=max(height[i],rm[i+1]);
           }

           int lm=0;
           int ans=0;
           for(int i=0;i<n;i++){
                   
                  lm=max(lm,height[i]); 
                 
                  ans+=min(lm,rm[i])-height[i];
           }
          
           return ans;







           // 4 2 0 3 2 5

           //  4 4 4 4 4 5
           //   5 5 5 5 5 5 
           //   0 2 4 1 2 0

        //    vector<int>rightmax(n,0);
        //    rightmax[n-1]=height[n-1];

        //    for(int i=n-2;i>=0;i--){
        //      rightmax[i]=max(height[i],rightmax[i+1]);
        //    }
        //    int leftmax=0;
        //    int ans=0;
        //    for(int i=0;i<n;i++){
                  
        //           leftmax=max(leftmax,height[i]);
                  
        //           ans+=min(leftmax,rightmax[i])-height[i];

        //    }
        //    return ans;



    }
};