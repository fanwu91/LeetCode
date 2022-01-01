#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int length_of_longest_substring(string s) {
		int longest = 0;
		int n = s.length(), j = 0;
		unordered_set<char> c_set;	
	
		for (int i = 0; i < n; ++i) {
			while (j < n && c_set.find(s[j]) == c_set.end()) {
				c_set.insert(s[j]);
				++j;
			}
			longest = max(longest, j - i);
			c_set.erase(s[i]);
		}

		return longest;
    }
};

