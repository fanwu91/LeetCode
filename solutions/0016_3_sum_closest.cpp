#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int three_sum_closest(vector<int>& nums, int target) {
        int n = nums.size();
        int distance = INT_MAX, result = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int l = i + 1, r = n - 1;
            
            while (l < r) {
                int total = nums[i] + nums[l] + nums[r];
                if (total == target) {
                    return target;
                } else if (total > target) {
                    --r;
                } else {
                    ++l;
                }
                
                if (abs(total - target) < distance) {
                    distance = abs(total - target);
                    result = total;
                }
            }
        }

        return result;
    }
};
