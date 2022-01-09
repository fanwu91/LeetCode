#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> three_sum(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3) {
            return {};
        }

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int target = 0 - nums[i];
            int l = i + 1, r = n - 1;
            
            while (l < r) {
                int total = nums[l] + nums[r];
                if (total == target) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;

                    while (l < r && nums[l] == nums[l-1]) {
                        ++l;
                    }
                    while (l < r && nums[r] == nums[r+1]) {
                        --r;
                    }
                } else if (total > target) {
                    --r;
                } else {
                    ++l;
                }
            }
        }

        return result;
    }
};