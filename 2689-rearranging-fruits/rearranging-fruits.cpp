#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(unordered_map<long long, long long>& total) {
        for (auto& entry : total) {
            if (entry.second % 2 != 0) return false;
        }
        return true;
    }

    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<long long, long long> total;
        for (int fruit : basket1) total[fruit]++;
        for (int fruit : basket2) total[fruit]++;

        if (!isPossible(total)) return -1;

        unordered_map<long long, long long> count1, count2;
        for (int fruit : basket1) count1[fruit]++;
        for (int fruit : basket2) count2[fruit]++;

        vector<long long> excess1, excess2;
        for (auto& entry : count1) {
            long long fruit = entry.first;
            long long current = entry.second;
            long long needed = total[fruit] / 2;
            while (current > needed) {
                excess1.push_back(fruit);
                current--;
            }
        }
        for (auto& entry : count2) {
            long long fruit = entry.first;
            long long current = entry.second;
            long long needed = total[fruit] / 2;
            while (current > needed) {
                excess2.push_back(fruit);
                current--;
            }
        }

        sort(excess1.begin(), excess1.end());
        sort(excess2.begin(), excess2.end(), greater<long long>());

        long long min_total_cost = 0;
        int n = excess1.size();
        int m = excess2.size();
        if (n != m) return -1;

        long long global_min = LLONG_MAX;
        for (auto& entry : total) {
            if (entry.first < global_min) {
                global_min = entry.first;
            }
        }

        for (int i = 0; i < n; ++i) {
            min_total_cost += min(min(excess1[i], excess2[i]), 2 * global_min);
        }

        return min_total_cost;
    }
};