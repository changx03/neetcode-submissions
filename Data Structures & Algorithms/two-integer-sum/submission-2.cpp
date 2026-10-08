#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) { return {}; }

        std::unordered_map<int, int> lookup_map{{nums[0], 0}};

        for (int i = static_cast<int>(nums.size() - 1); i > 0; i--) {
            int leftover = target - nums[i];
            if (lookup_map.find(leftover) != lookup_map.end()) {
                auto j = lookup_map.at(leftover);
                if (j > i) { return {i, j}; }
                else { return {j, i}; } 
            }
            lookup_map.insert({nums[i], i});
        }

        return {};
    }
};
