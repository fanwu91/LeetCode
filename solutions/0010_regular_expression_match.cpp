#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool is_match(const string& s, const string& p) {
        int n = s.length(), m = p.length();

        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));

        f[0][0] = true;

        for (int j = 1; j < m + 1; ++j) {
            if (p[j-1] == '*') {
                f[0][j] = f[0][j-2];
            }
        }
        
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                if (p[j-1] != '*') {
                    f[i][j] = f[i-1][j-1] && (p[j-1] == '.' || p[j-1] == s[i-1]);
                } else {
                    if (p[j-2] == s[i-1] || p[j-2] == '.') {
                        f[i][j] = f[i][j-2] || f[i-1][j];
                    } else {
                        f[i][j] = f[i][j-2];
                    }
                }

            }
        }

        return f[n][m];
    }
};
