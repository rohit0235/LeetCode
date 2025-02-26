class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
            int n=nums.size();
            int currentsum=0;
            int maxsum=INT_MIN;

            for (int i=0;i<n;i++){
                  currentsum+=nums[i];
                   
                  if (currentsum>maxsum){
                        maxsum=currentsum;
                  }

                  if (currentsum<0){
                      currentsum=0;
                  }

            }

            int current=0;
            int minsum=INT_MAX;

            for (int i=0;i<n;i++){
                  current+=nums[i];
                   
                  if (current<minsum){
                        minsum=current;
                  }

                  if (current>0){
                      current=0;
                  }

            }
        //    cout<<minsum<<" "<<maxsum;
              return max(abs(minsum),maxsum);
        //     int maxabs=0;
        //    for (int i=0;i<n;i++){
        //          int sum=0;
        //          for (int j=i;j<n;j++){   
        //                sum+=nums[j];
        //                maxabs=max(abs(sum),maxabs);
        //          } 
        //    }
            
        //     return maxabs;
    }
};