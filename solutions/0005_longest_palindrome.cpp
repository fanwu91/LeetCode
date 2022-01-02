#include <string>

class Solution {
public:
    std::string longest_palindrome(std::string s) {
        int n = s.length(), longest = 0;
        std::string result;

        for (int i = 0; i < n; ++i) {
            // even
            int l = i, r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
            }

            if (longest < r - l - 1) {
                longest = r - l - 1;
                result = s.substr(l + 1, longest);
            }

            // odd
            l = r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
            }
            
            if (longest < r - l - 1) {
                longest = r - l - 1;
                result = s.substr(l + 1, longest);
            }
        }

        return result;
    }
};
