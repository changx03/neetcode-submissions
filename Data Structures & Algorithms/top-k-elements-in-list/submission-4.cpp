#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        size_t greatest{0};
        for (int num : nums) {
            counter[num]++;
            if (static_cast<size_t>(counter[num]) > greatest) { 
                greatest = static_cast<size_t>(counter[num]); 
            }
        }

        vector<vector<int>> buckets{greatest + 1};
        for (const auto& [val, count] : counter) {
            buckets[count].push_back(val);
        }

        vector<int> res;
        res.reserve(k);
        for (size_t i = greatest; res.size() < static_cast<size_t>(k); i--) {
            for (int num : buckets[i]) {
                res.push_back(num);
            }
        }
        return res;
    }
};
