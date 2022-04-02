class Solution {
public:
    int strStr(stringstring haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        if (n < m) {
            return -1;
        }

        for (int i = 0; i < n - m + 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (needle[j] != haystack[i + j]) {
                    break;
                }
                
                if (j == m - 1) {
                    return i;
                }
            }
        }
        
        return -1;
    }
};
