class Solution {
public:
     struct cmp{
                 bool operator ()(pair<int,int>&a , pair<int,int>&b){
                    return a.second<b.second;
                }
     };

    vector<int> topKFrequent(vector<int>& nums, int k) {
           sort(nums.begin(),nums.end());
             priority_queue<pair<int,int>,vector<pair<int,int>>, cmp>pq; 
             int n = nums.size();
            int count =1;
            for(int i=1;i<nums.size();i++){
                      
                       if (nums[i]==nums[i-1]) count++;

                       else{
                           pq.push({nums[i-1],count});
                           count =1;
                       }
                      
                  
            }

           pq.push({nums[n-1],count});

             
           vector<int>ans;
           
           while (!pq.empty() && k--){
               int x = pq.top().first;
                ans.push_back(x);
                pq.pop();
            }
             return ans;
                   
    }
};