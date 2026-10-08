#include <set>
#include <vector>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) { return false; }

        std::vector<char> vec_t(t.begin(), t.end());
        std::multiset<char> set_s{s.begin(), s.end()};

        for (auto char_t : vec_t) {
            auto it = set_s.find(char_t);
            if (it == set_s.end()) { return false; }
            set_s.erase(it);
        }
        
        return true;
    }
};
