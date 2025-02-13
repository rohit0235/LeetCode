class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
                  
              //      2 11 10 1 3
              //     1   2 3 10 11
              //     4 3 10 11 
              //     10 10 11

              priority_queue<long long,vector<long long>,greater<long long>>pq;
              for (long long i:nums) pq.push(i);
              long long count=0;
              while (pq.size()>1 && pq.top()<k){
                     count++;
                     long long firstnu=pq.top();
                     pq.pop();
                     long long second=pq.top();
                     pq.pop();

                     pq.push(2*min(firstnu,second)+max(firstnu,second));
                     
              }    

              return count;
    }
};