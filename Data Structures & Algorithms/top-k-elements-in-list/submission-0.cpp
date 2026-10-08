#include <unordered_map>
#include <utility> // pair
#include <algorithm> // sort

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }

        vector<pair<int, int>> count_val;
        for (const auto& item : counter) {
            count_val.push_back({ item.second, item.first });
        }
        sort(count_val.begin(), count_val.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        });
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(count_val[i].second);
        }
        return res;
    }
};
