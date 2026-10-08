#include <array>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        groups.reserve(strs.size());

        for (const auto& str : strs) {
            groups[encodeStr(str)].push_back(str);
        }

        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto& [key, group] : groups) {
            res.push_back(std::move(group));
        }

        return res;
    }

    static string encodeStr(const string& str) {
        array<int, 26> code{}; // '{}' initialise all elements to 0 
        for (std::size_t i = 0; i < str.size(); i++) {
            code[str[i] - 'a']++;
        }
        string key;
        key.reserve(26);
        for (int c : code) {
            key += static_cast<char>(c); // holds 127 > 100
        }
        return key;
    }
};
