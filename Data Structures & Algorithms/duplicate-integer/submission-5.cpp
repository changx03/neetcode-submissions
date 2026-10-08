#include <unordered_set>

class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        seen.reserve(nums.size());
        
        for (int val : nums) {
            if (seen.find(val) != seen.end()) {
                return true;
            }
            seen.insert(val);
        }

        return false;
    }
};