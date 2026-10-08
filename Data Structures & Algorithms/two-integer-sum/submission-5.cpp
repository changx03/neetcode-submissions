#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> lookup_map; // { value, index }
        lookup_map.reserve(nums.size());

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            auto it = lookup_map.find(target - nums[i]);

            if (it != lookup_map.end()) {
                return {it->second, i}; 
            }
            lookup_map.insert({nums[i], i});
        }

        return {};
    }
};
