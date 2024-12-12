class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<int>pq;
        int n=gifts.size();
        for (int i=0;i<n;i++){
            pq.push(gifts[i]);
        }

        while (k--){
            int s=pq.top();
            pq.pop();
            pq.push(sqrt(s));

        }
           long long result=0;
           int t=pq.size();
        while (t--){
                 result+=pq.top();
                 pq.pop();
        }
        return result;
    }
};
