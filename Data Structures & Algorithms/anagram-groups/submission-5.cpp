#include <array>
#include <unordered_map>
#include <utility>  // move

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        groups.reserve(strs.size());

        for (string& str : strs) {
            auto key = encode(str);
            groups[key].push_back(str);
        }

        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto& item : groups) {
            res.push_back(std::move(item.second));
        }
        return res;
    }

    static string encode(const string& str) {
        array<int, 26> alphabet;
        for (size_t i = 0; i < str.size(); i++) {
            alphabet[str[i] - 'a']++;
        }

        string res;
        res.reserve(26);
        for (int i : alphabet) {
            res += static_cast<char>(i);
        }
        return res;
    }
};
