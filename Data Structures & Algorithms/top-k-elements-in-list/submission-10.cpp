#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, size_t> counter; // key: num, value: count
        counter.reserve(nums.size());
        size_t max{0};
        for (int& n : nums) {
            counter[n]++;
            if (counter.at(n) > max) { max = counter.at(n); }
        }

        vector<vector<int>> buckets{max + 1};
        for (const auto& [num, count] : counter) {
            buckets[count].push_back(num);
        }

        vector<int> res;
        res.reserve(k);
        for (size_t i = buckets.size() - 1; res.size() < k; i--) {
            for(int& num : buckets[i]) {
                res.push_back(num);
            }
        }
        return res;
    }
};
