#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();

        while (l < r) {
            int m = l + ((r - l) >> 1);

            if (nums[m] == target) {
                return m;
            }

            if (target > nums[n - 1]) {
                if (nums[m] < target && nums[m] > nums[n - 1]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            } else {
                if (nums[m] <= nums[n - 1] && nums[m] > target) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
        }

        return nums[l] == target ? l : -1;
    }
};
