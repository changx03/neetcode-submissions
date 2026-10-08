#include <array>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }
        array<int, 26> alphabet{}; // initialise zeros

        for (size_t i = 0; i < s.size(); i++) {
            alphabet[s[i] - 'a']++;
            alphabet[t[i] - 'a']--;
        }

        for (const auto& c : alphabet) {
            if (c != 0) { return false; }
        }

        return true;
    }
};
