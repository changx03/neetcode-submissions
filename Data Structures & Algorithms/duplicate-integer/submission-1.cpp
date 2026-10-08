#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        std::set<int> my_set;
        for (int val : nums) {
            if (my_set.contains(val)) { return true; }
            my_set.insert(val);
        }

        return false;
    }
};