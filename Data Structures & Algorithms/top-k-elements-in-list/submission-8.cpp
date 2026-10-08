#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> seen; // key: num, value: count
        seen.reserve(nums.size());
        int max{0};

        for (const int& num : nums) {
            seen[num]++;
            if (seen.at(num) > max) {
                max = seen.at(num);
            }
        }

        vector<vector<int>> buckets{static_cast<size_t>(max + 1)};
        for (const auto& [num, count] : seen) {
            buckets[count].push_back(num);
        }

        vector<int> res;
        const size_t kt = static_cast<size_t>(k);
        res.reserve(kt);
        for (size_t i = buckets.size() - 1; res.size() < kt; i--) {
            for (int val : buckets.at(i)) {
                res.push_back(val);   
            }
        }
        return res;
    }
};
