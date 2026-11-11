#include <unordered_map>

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;  // key: number, value: index

        const int n_size = static_cast<int>(nums.size());
        for (int i = 0; i < n_size; i++) {
            int leftover = target - nums[i];
            if (seen.contains(leftover)) {
                return {seen[leftover], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};
