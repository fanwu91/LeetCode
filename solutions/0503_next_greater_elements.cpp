#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> next_greater_elements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> stk; // mono-descreasing stack store index

        for (int i = 0; i < 2 * n - 1; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                result[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }

        return result;
    }
};
