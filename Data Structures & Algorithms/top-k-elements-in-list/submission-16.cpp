#include <queue>       // priority_queue
#include <functional>  // greater
#include <utility>     // pair
#include <unordered_map>

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> seens;  // key: num, value: counts
        seens.reserve(nums.size());
        for (auto& i : nums) {
            seens[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>>
            ordered_queue;

        for (auto& [num, count] : seens) {
            ordered_queue.push({count, num});
            if (ordered_queue.size() > k) {
                ordered_queue.pop();  // pop the 1st (lowest count)
            }
        }

        vector<int> res;
        res.reserve(k);
        for (; !ordered_queue.empty(); ordered_queue.pop()) {
            res.push_back(ordered_queue.top().second);
        }
        return res;
    }
};
