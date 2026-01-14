class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        struct Event {
            int x, y1, y2, type;
            bool operator<(const Event& other) const {
                return x < other.x;
            }
        };

        vector<Event> events;
        vector<int> y_coords;
        for (const auto& s : squares) {
            events.push_back({s[0], s[1], s[1] + s[2], 1});
            events.push_back({s[0] + s[2], s[1], s[1] + s[2], -1});
            y_coords.push_back(s[1]);
            y_coords.push_back(s[1] + s[2]);
        }
        sort(events.begin(), events.end());
        sort(y_coords.begin(), y_coords.end());
        y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());

        int m = y_coords.size();
        auto get_idx = [&](int y) {
            return lower_bound(y_coords.begin(), y_coords.end(), y) - y_coords.begin();
        };

        vector<int> count(4 * m, 0);
        vector<long long> tree(4 * m, 0);

        auto update = [&](auto self, int node, int start, int end, int l, int r, int val) -> void {
            if (l >= end || r <= start) return;
            if (l <= start && end <= r) {
                count[node] += val;
            } else {
                int mid = (start + end) / 2;
                self(self, 2 * node, start, mid, l, r, val);
                self(self, 2 * node + 1, mid, end, l, r, val);
            }
            if (count[node] > 0) {
                tree[node] = y_coords[end] - y_coords[start];
            } else if (end - start > 1) {
                tree[node] = tree[2 * node] + tree[2 * node + 1];
            } else {
                tree[node] = 0;
            }
        };

        vector<double> strip_areas(m - 1, 0.0);
        for (int i = 0; i < (int)events.size() - 1; ++i) {
            update(update, 1, 0, m - 1, get_idx(events[i].y1), get_idx(events[i].y2), events[i].type);
            
            double width = events[i + 1].x - events[i].x;
            if (width > 0) {
                auto calculate_strips = [&](auto self, int node, int start, int end) -> void {
                    if (tree[node] == 0) return;
                    if (count[node] > 0) {
                        for (int k = start; k < end; ++k) {
                            strip_areas[k] += (double)(y_coords[k + 1] - y_coords[k]) * width;
                        }
                        return;
                    }
                    if (end - start > 1) {
                        int mid = (start + end) / 2;
                        self(self, 2 * node, start, mid);
                        self(self, 2 * node + 1, mid, end);
                    }
                };
                calculate_strips(calculate_strips, 1, 0, m - 1);
            }
        }

        double total_area = 0;
        for (double a : strip_areas) total_area += a;

        double target = total_area / 2.0;
        double current_sum = 0;
        for (int i = 0; i < m - 1; ++i) {
            if (current_sum + strip_areas[i] >= target) {
                double needed = target - current_sum;
                double strip_height = y_coords[i + 1] - y_coords[i];
                double strip_width = strip_areas[i] / strip_height;
                return y_coords[i] + (needed / strip_width);
            }
            current_sum += strip_areas[i];
        }

        return y_coords.back();
    }
};