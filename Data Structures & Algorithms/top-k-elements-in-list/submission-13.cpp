#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> seen; // key: num, value: count
        seen.reserve(nums.size());
        int greatest{0};

        for (auto& i : nums) {
            seen[i]++;
            if (greatest < seen[i]) {
                greatest = seen[i];
            }
        }

        vector<vector<int>> buckets(greatest + 1);
        for (auto& p : seen) { // pair
            buckets[p.second].push_back(p.first);
        }

        vector<int> res;
        res.reserve(k);
        for (int i = buckets.size() - 1; i >= 0 && res.size() < k; i--) {
            for (auto& num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) break;
            }
        }
        return res;
    }
};
