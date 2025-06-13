class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0)
            return false;
        if (nums.size() == 1)
            return true;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        int maxi = INT_MIN;

        for (auto i : s) {

            if (s.find(i - 1) == s.end()) {
                int len = 1;
                int x = i;
                while (s.find(x) != s.end()) {
                    len=len+1;
                    x=x+1;
                }
                maxi = max(maxi, len);
            }
        }

        return maxi-1;

        //    map<int,int>mp;
        //     int n=nums.size();
        //    for (int i=0;i<n;i++) mp[i]++;

        //    for(auto i:mp){
        //             if ()
        //    }
    }
};