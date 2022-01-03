#include <vector>
#include <string>

using namespace std;

/*
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
*/
class Solution {
public:
    string convert(string s, int num_rows) {
        if (s.length() == 1 || numRows == 1) {
            return s;
        }
        vector<string> rows(numRows, string());
        bool go_down = false;
        int n = s.length(), row = 0;

        for (int i = 0; i < n; ++i) {
           rows[row] += s[i];
           if (row == numRows - 1 || row == 0) {
               go_down = !go_down;
           }
           row += go_down ? 1 : -1;
        }

        string result;

        for (const auto& row : rows) {
            result += row;
        }

        return result;
    }
};