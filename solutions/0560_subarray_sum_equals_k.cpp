#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> pre_sum(n + 1, 0);

        for (int i = 1; i < n + 1; ++i) {
            pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
        }

        std::unordered_map<int, int> tmap;
        int cnt = 0;
        for (const auto& sum : pre_sum) {
            auto iter = tmap.find(sum);
            if (iter != tmap.end()) {
                cnt += iter->second;
            }
            ++tmap[sum + k];
        }

        return cnt;
    }
};
