#include <array>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, std::size_t> seen; // { code, index }
        vector<vector<string>> res;
        std::size_t idx = 0;

        for (string str : strs) {
            const auto code = wordEncoder(str);
            auto it = seen.find(code);
            if (it != seen.end()) {
                res[it->second].push_back(str);
            }
            else {
                seen.insert({ code, idx });
                idx++;
                res.push_back({ str });
            }
        }

        return res;
    }

    string wordEncoder(const string& str) {
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
