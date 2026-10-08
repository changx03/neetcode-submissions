#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        std::unordered_set<int> my_set;
        for (int val : nums) {
            if (my_set.find(val) != my_set.end()) { return true; }
            my_set.insert(val);
        }

        return false;
    }
};