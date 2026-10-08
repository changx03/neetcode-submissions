#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::size_t> lookup_map{{nums[0], 0}};

        for (std::size_t i = 1; i < nums.size(); i++) {
            int leftover = target - nums[i];
            if (lookup_map.find(leftover) != lookup_map.end()) {
                return vector<int>{
                    static_cast<int>(lookup_map.at(leftover)),
                    static_cast<int>(i)};
            }
            lookup_map.insert({nums[i], i});
        }

        return vector<int>();
    }
};
