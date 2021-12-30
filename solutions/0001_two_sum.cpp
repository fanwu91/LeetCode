#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> two_sum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (table.find(nums[i]) != table.end()) {
                return { table[nums[i]], i };
            } else {
                table[target - nums[i]] = i;
            }
        }

        return { -1, -1 };
    }
};
