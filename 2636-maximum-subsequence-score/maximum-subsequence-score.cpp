class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> s;
        
        // Pair nums2[i] with nums1[i] and sort in descending order based on nums2[i]
        for (int i = 0; i < n; i++) {
            s.push_back({nums2[i], nums1[i]});
        }
        sort(s.rbegin(), s.rend()); 
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, score = 0;
        
        // Process first k elements
        for (int i = 0; i < k; i++) {
            sum += s[i].second;
            minHeap.push(s[i].second);
        }
        score = sum * s[k - 1].first; // Initial score
        
        // Sliding window approach
        for (int i = k; i < n; i++) {
            sum += s[i].second;
            minHeap.push(s[i].second);
            
            sum -= minHeap.top(); // Remove the smallest element
            minHeap.pop();
            
            score = max(score, sum * s[i].first);
        }
        
        return score;
    }
};
