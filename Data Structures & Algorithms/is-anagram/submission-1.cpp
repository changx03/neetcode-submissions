#include <set>
#include <vector>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }

        std::multiset<char> set_s{s.begin(), s.end()};

        for (std::size_t i = 0; i < t.size(); i++) {
            const char char_t = t[i];
            const auto it = set_s.find(char_t);
            if (it == set_s.end()) { return false; }
            set_s.erase(it);
        }

        return true;
    }
};
