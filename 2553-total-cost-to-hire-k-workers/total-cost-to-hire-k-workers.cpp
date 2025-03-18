class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;   // Left candidates
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;  // Right candidates

        long long cost = 0; // Changed from int to long long
        int n = costs.size();
        int i = 0, j = n - 1;

        // Fill initial left pq and right pq without overlap
        for (; i < candidates && i <= j; i++) {
            pq.push({costs[i], i});
        }
        for (; j >= n - candidates && j >= i; j--) {
            pq2.push({costs[j], j});
        }

        // Now pick k workers
        while (k--) {
            if (!pq.empty() && (pq2.empty() || pq.top().first <= pq2.top().first)) {
                cost += pq.top().first;
                // int idx = pq.top().second;
                pq.pop();
                if (i <= j) {
                    pq.push({costs[i], i});
                    i++;
                }
            } else {
                cost += pq2.top().first;
                // int idx = pq2.top().second;
                pq2.pop();
                if (i <= j) {
                    pq2.push({costs[j], j});
                    j--;
                }
            }
        }

        return cost;
    }
};
