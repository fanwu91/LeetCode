#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StateMachine {
private:
    typedef long long int64;
    int64 ans;
    int sign;
    string state;

    unordered_map< string, vector<string> > table = {
        /* ' ', '+/-', '9', 'a' */
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int to_state(char c) {
        if (isspace(c)) return 0;
        if (c == '+' || c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }

    void go_to_state(char c) {
        state = table[state][to_state(c)];

        if (state == "signed") {
            sign = c == '+' ? 1 : -1;
        } else if (state == "in_number") {
            ans = ans * 10 + (c - '0');
            ans = sign == 1 ? min(ans, static_cast<int64>(INT_MAX)) 
                            : min(ans, 0 - static_cast<int64>(INT_MIN));
        }
    }
public:
    StateMachine() : ans(0), sign(1), state("start") {}

    int get_number(string s) {
        for (const auto& c : s) {
            go_to_state(c);
        }
        
        return static_cast<int>(ans * sign);
    }
};

class Solution {
public:
    int myAtoi(string s) {
        StateMachine sm;
        return sm.get_number(s);
    }
};
