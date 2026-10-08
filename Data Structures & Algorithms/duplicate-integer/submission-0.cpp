#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) { return false; }

        std::set<int> my_set{nums[0]};
        for (std::size_t i = 1; i < nums.size(); i++) {
            if (my_set.contains(nums[i])) { return true; }
            my_set.insert(nums[i]);
        }

        return false;
    }
};