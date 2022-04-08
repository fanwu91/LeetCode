class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = ((dividend ^ divisor) >> 31 & 0x1) ? -1 : 1;
        int64_t ldividend = abs((int64_t)dividend);
        int64_t ldivisor = abs((int64_t)divisor);

        int64_t result = 0;
        while (ldividend >= ldivisor) {
            int64_t i = 1;
            int64_t tmp = ldivisor;

            while (ldividend >= tmp) {
                ldividend -= tmp;
                result += i;
                i <<= 1;
                tmp <<= 1;
            }
        }

        result *= sign;

        if (result > INT_MAX || result < INT_MIN) {
            return INT_MAX;
        }

        return (int)result;
    }
};
