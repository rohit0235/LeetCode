class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<long long> count(n, 0);
        priority_queue<int, vector<int>, greater<int>> free_rooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_rooms;

        for (int i = 0; i < n; i++) {
            free_rooms.push(i);
        }

        for (auto& m : meetings) {
            long long start = m[0];
            long long end = m[1];

            while (!busy_rooms.empty() && busy_rooms.top().first <= start) {
                free_rooms.push(busy_rooms.top().second);
                busy_rooms.pop();
            }

            if (!free_rooms.empty()) {
                int room = free_rooms.top();
                free_rooms.pop();
                count[room]++;
                busy_rooms.push({end, room});
            } else {
                auto [available_time, room] = busy_rooms.top();
                busy_rooms.pop();
                count[room]++;
                busy_rooms.push({available_time + (end - start), room});
            }
        }

        int result = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[result]) {
                result = i;
            }
        }

        return result;
    }
};