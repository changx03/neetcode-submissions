#include <array>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::array<int, 26> alphabet{};

        for (size_t i = 0; i < s.size(); i++) {
            alphabet[s[i] - 'a']++;
            alphabet[t[i] - 'a']--;
        }

        for (const auto& count : alphabet) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};
