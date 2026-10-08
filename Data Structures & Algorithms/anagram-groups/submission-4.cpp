#include <array>
#include <unordered_map>
#include <utility> // move

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups; // key: encoded_str, value: matching strs
        groups.reserve(strs.size());

        for (const auto& str : strs) {
            groups[encode(str)].push_back(str);
        }

        vector<vector<string>> res;
        res.reserve(groups.size());
        for (const auto& [key, values] : groups) {
            res.push_back(std::move(values));
        }
        return res;
    }

    static string encode(const string& str) {
        array<int, 26> alphabet{};
        for (size_t i = 0; i < str.size(); i++) {
            alphabet[str[i] - 'a']++;
        }

        string res;
        res.reserve(26);
        for (int a : alphabet) {
            res += static_cast<char>(a);
        }
        return res;
    }
};
