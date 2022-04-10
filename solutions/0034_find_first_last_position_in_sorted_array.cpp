class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return { -1, -1 };
        }
        return {lower(nums, target), upper(nums, target)};
    }
private:
    int lower(const vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return nums[l] == target ? l : -1;
    }

    int upper(const vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = l + ((r - l) >> 1) + 1;
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        return nums[r] == target ? r : -1;
    }
};
