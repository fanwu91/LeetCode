#include <vector>

using namespace std;

class Solution {
public:
    int max_area(const vector<int>& height) {
        int result = 0, n = height.size();
        int l = 0, r = n - 1;

        while (l < r) {
            int w = r - l;
            int h = min(height[l], height[r]);
            if (w * h > result) {
                result = w * h;
            }
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return result;
    }
};
