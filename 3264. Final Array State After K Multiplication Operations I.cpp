class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
                 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            
            for (int  i=0;i<nums.size();i++){
                pq.push({nums[i],i});
            }

            while (k--){
               auto tops=pq.top();
                pq.push({tops.first*multiplier,tops.second});
                pq.pop();
            }

            while (!pq.empty()){
                auto tops=pq.top();
                nums[tops.second]=tops.first;
                pq.pop();
            }

            return nums;
  


    }
};
