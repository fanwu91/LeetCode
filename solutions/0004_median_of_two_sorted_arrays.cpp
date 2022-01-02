#include <vector>

class Solution {
public:
    double find_median_sorted_arrays(
        const vector<int>& nums1, 
        const vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return find_median_sorted_arrays(nums2, nums1);
        }

        int n = nums1.size(), m = nums2.size();
        int l = 0, r = n, total = n + ((m - n + 1) >> 1);

        while (l < r) {
            int i = l + ((r - l) >> 1) + 1;
            int j = total - i;

            if (nums1[i - 1] > nums2[j]) {
                r = i - 1;
            } else {
                l = i;
            }
        }

        int i = l, j = total - l;
        int A1 = i == 0 ? INT_MIN : nums1[i - 1];
        int B1 = j == 0 ? INT_MIN : nums2[j - 1];
        int A2 = i == n ? INT_MAX : nums1[i];
        int B2 = j == m ? INT_MAX : nums2[j];

        if ((n + m) % 2 == 0) {
            return (max(A1, B1) + min(A2, B2)) / 2.0;
        }

        return max(A1, B1);
    }
}; 