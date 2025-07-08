
class Solution {
public:
    int n;
    std::vector<std::vector<int>> memo;

    int get_next_idx(const std::vector<std::vector<int>>& ev, int end_t, int start_idx) {
        auto iter = std::upper_bound(ev.begin() + start_idx, ev.end(), end_t,
                                   [](int target, const std::vector<int>& event) {
                                       return target < event[0];
                                   });
        return std::distance(ev.begin(), iter);
    }

    int solve(const std::vector<std::vector<int>>& ev, int k, int i) {
        if (i >= n) return 0;
        if (k == 0) return 0;

        if (memo[i][k] != -1) {
            return memo[i][k];
        }

        int no_take = solve(ev, k, i + 1);

        int take_val = ev[i][2];
        int curr_end = ev[i][1];

        int next_i = get_next_idx(ev, curr_end, i + 1);

        take_val += solve(ev, k - 1, next_i);
        
        return memo[i][k] = std::max(take_val, no_take);
    }

    int maxValue(std::vector<std::vector<int>>& events, int k_limit) {
        n = events.size();

        std::sort(events.begin(), events.end());

        memo.assign(n + 1, std::vector<int>(k_limit + 1, -1));

        return solve(events, k_limit, 0);
    }
};