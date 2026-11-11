#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // key: number, value: index

        const int n_size = static_cast<int>(nums.size());
        for (int i = 0; i < n_size; i++) {
            auto it = seen.find(target - nums[i]);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen.emplace(nums[i], i);
        }

        return {};
    }
};
