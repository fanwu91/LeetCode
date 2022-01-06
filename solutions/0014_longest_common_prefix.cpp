#include <string>

using namespace std;

class Solution {
public:
    string longest_common_prefix(const vector<string>& strs) {
        if (strs.empty()) {
            return string();
        }

        string result;

        for (int i = 0; i < 201; ++i) {
            char c = strs[0][i];

            for (int j = 0; j < strs.length(); ++j) {
                if (strs[j].length() <= i || strs[j][i] != c) {
                    return result;
                }
            }

            result += c;
        }

        return result;
    }
};