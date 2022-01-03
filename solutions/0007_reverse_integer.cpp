class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int d = x % 10;

            if (result > INT_MAX / 10 || result == INT_MAX / 10 && d > 7) {
                return 0;
            }

            if (result < INT_MIN / 10 || result == INT_MIN / 10 && d < -8) {
                return 0;
            }

            result = result * 10 + d;
            x /= 10;
        }

        return result;
    }
};
