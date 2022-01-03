#include <string>
#include <vector>

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
    
    std::string longest_palindrome_dp(std::string s) {
                int n = s.length();
        vector<vector<bool>> f(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            f[i][i] = true;
        }

        // f[i][j] == f[i+1][j-1] & s[i] == s[j]
        int longest = 1, begin = 0;

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] == s[j]) {
                    if (j - i < 3) {
                        f[i][j] = true;
                    } else {
                        f[i][j] = f[i+1][j-1];
                    }
                }

                if (f[i][j] && j - i + 1 > longest) {
                    longest = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, longest);
    }
};
