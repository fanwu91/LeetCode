#include <stack>
#include <vector>

class Solution {
public:
    vector<int> daily_temperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                result[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return result;
    }
};
