#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value, index
        seen.reserve(nums.size());

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            const int remainder = target - nums[i];
            const auto it = seen.find(remainder);
            if (it != seen.end()) {
                return {it->second, i}; // new index is always greater 
            }
            seen.emplace(nums[i], i);
        }

        return {};
    }
};
