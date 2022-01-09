#include <unordered_set>
#include <string>

using namespace std;

class Solution {
private:
    char match(char left) {
        if (left == ')') return '(';
        if (left == ']') return '[';
        return '{';
    }
public:
    bool is_valid(string s) {
        stack<char> stk;
        unordered_set<char> lefts({'(', '[', '{'});

        for (const auto& c : s) {
            if (lefts.find(c) != lefts.end()) {
                stk.push(c);
            } else if (stk.empty() || match(c) != stk.top()) {
                return false;
            } else {
                stk.pop();
            }
        }

        return stk.empty();
    }
};
