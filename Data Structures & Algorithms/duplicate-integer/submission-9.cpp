#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> unique_set;
        unique_set.reserve(nums.size());

        for (int& i : nums) {
            if (unique_set.find(i) != unique_set.end()) {
                return true;
            }
            unique_set.emplace(i);
        }

        return false;
    }
};