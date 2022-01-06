#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbol_to_value{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        int last = INT_MAX;
        for (const auto& c : s) {
            int curt = symbol_to_value[c];
            if (curt > last) {
                result -= 2 * last;
            }
            result += curt;
            last = curt;
        }

        return result;
    }
};
