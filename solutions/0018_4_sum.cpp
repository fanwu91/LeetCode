#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> four_sum(vector<int>& nums, int target) {
        int n = nums.size();
        
        if (n < 4) {
            return {};
        }

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                if (j != i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int l = j + 1, r = n - 1;
                int rtarget = 0 - target;

                while (l < r) {
                    int total = nums[l] + nums[r];
                    if (total == rtarget) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                        while (l < r && nums[l] == nums[l-1]) {
                            ++l;
                        }
                        while (l < r && nums[r] == nums[r+1]) {
                            --r;
                        }
                    } else (total > rtarget) {
                        --r;
                    } else {
                        ++l;
                    }
                }
            }
        }

        return result;        
    }
};
