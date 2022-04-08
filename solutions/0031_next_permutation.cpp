#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums)
    {
        bool decreasing = true;
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                decreasing = false;
                break;
            }
        }

        if (decreasing){
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int index = n - 1;
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] > nums[i-1]) {
                index = i - 1;
                break;
            }
        }
        
        for (int i = n - 1; i > index; --i) {
            if (nums[i] > nums[index]) {
                swap(nums, i, index);
                break;
            }
        }

        int l = index + 1;
        int r = n - 1;
        while (l < r) {
            swap(nums, l++, r--);
        }
    }
private:
    void swap(vector<int>& nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
