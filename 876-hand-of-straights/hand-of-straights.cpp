class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        unordered_map<int, int> mp;
        sort(hand.begin(),hand.end());
        for (int i = 0; i < hand.size(); i++) {

               mp[hand[i]]++;

        
                bool found = true;
                for (int j = 0; j < groupSize; j++) {

                    if (mp.find(hand[i] - j) == mp.end()) {
                        found = false;
                        break;
                    }
                }

                if (found) {

                    for (int j = 0; j < groupSize; j++) {
                          mp[hand[i]-j]--;
                          if (mp[hand[i]-j]==0) mp.erase(hand[i]-j);
                    }
                }
            
        }

        return mp.size()==0;
    }
};