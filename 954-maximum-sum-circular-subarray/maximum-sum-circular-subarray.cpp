class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
            
            //    1 -2 3 -2 1 -2 3 -2
               int n =nums.size();
          

            //    for(int i=0;i<n;i++){
            //             nums.push_back(nums[i]);
            //    }   
               
              int summin =INT_MAX;
              int currentsummin=0;
              int summax=INT_MIN;
             int currentsummax=0;
            for(int i=0;i<n;i++){
                    
                           currentsummin+=nums[i];     
                        

                           summin=min(summin,currentsummin);
                         if (currentsummin>0){
                                    currentsummin=0;
                             }

                           currentsummax+=nums[i];     
                        

                           summax=max(summax,currentsummax);
                           if (currentsummax<0){
                                    currentsummax=0;
                             }


            }

            int total =accumulate(nums.begin(),nums.end(),0);
   if (summax < 0) { // Changed condition from 'total < 0' to 'summax < 0'
    return summax;
}
return std::max(summax, total - summin);

           
    }
};