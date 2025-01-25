class Solution {
public:
    int findKthLargest(vector<int>& nums, int &k) {

           
          int minval=*min_element(nums.begin(),nums.end());
          int maxval=*max_element(nums.begin(),nums.end());

          vector<int>maxc(maxval-minval+1,0);

          for (int i:nums){
             maxc[i-minval]++;
          }
        
          for (int i=maxc.size()-1;i>=0;i--){
               
                  if (maxc[i]!=0){
                        
                        k-=maxc[i];
                  }   if (k<1 && maxc[i]!=0)  return i+minval;
                   
          }
           return -1;




        //   priority_queue<int>pq;
        //   int n =nums.size();
        //   for (int i:nums){
        //     pq.push(i);
        //   }
        //   while (k>1){
        //     pq.pop();
        //     k--;
        //   }
        //   return pq.top();
        //   sort(nums.rbegin(),nums.rend());
        //   return nums[k-1];
    }
};