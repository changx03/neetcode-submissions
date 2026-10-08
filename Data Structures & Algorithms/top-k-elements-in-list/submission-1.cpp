#include <unordered_map>
#include <utility> // pair
#include <algorithm> // sort

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        int greatest{0};
        for (int num : nums) {
            counter[num]++;
            if (counter[num] > greatest) { greatest = counter[num]; }
        }

        vector<vector<int>> buckets(greatest + 1);
        for (const auto& [val, count] : counter) {
            buckets[count].push_back(val);
        }

        vector<int> res;
        res.reserve(k);
        for (int i = static_cast<int>(buckets.size() - 1); static_cast<int>(res.size()) < k; i--) {
            for (int num : buckets[i]) {
                res.push_back(num);
            }
        }
        return res;
    }
};
