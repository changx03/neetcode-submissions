#include <array>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }

        std::array<int, 26> alphabet_counter;

        for (std::size_t i = 0; i < t.size(); i++) {
            alphabet_counter[s[i] - 'a']++;
            alphabet_counter[t[i] - 'a']--;
        }

        for(auto count : alphabet_counter) {
            if (count != 0 ) { return false; }
        }

        return true;
    }
};
