class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
     unordered_map<int, int> frequencyMap;

    // Count the frequency of each number
    for (int num : nums) {
        // If the number is not in the map, add it with a count of 1
        if (frequencyMap.find(num) == frequencyMap.end()) {
            frequencyMap[num] = 1;
        } else {
            // If the number is already in the map, increment its count
            frequencyMap[num]++;
        }
    }

    // Find the maximum frequency
    int maxFrequency = 0;
    for (const auto& pair : frequencyMap) {
        maxFrequency = std::max(maxFrequency, pair.second);
    }

    // Count elements with the maximum frequency
    int totalFrequency = 0;
    for (const auto& pair : frequencyMap) {
        if (pair.second == maxFrequency) {
            totalFrequency += pair.second;
        }
    }
    return totalFrequency;
    }

};