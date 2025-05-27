class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>> pq;
int c=0;
    KthLargest(int k, vector<int>& nums) {
        c=k;
        for(int i:nums){
             pq.push(i);
        }
    }
    

    // sort(s.begin(),s.end());
    
    int add(int val) {
        pq.push(val);
         while (pq.size()>c){
             pq.pop();
         }

         return pq.top();
         
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */