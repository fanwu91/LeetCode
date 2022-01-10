#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<string>& result, int left, int right, const string& tmp) {
        if (left == 0 && right == 0) {
            result.push_back(tmp);
            return;
        }

        if (left < 0 || right < 0 || left > right) {
            return;
        }

        dfs(result, left - 1, right, tmp + '(');
        dfs(result, left, right - 1, tmp + ')');
    }
public:
    vector<string> generate_parenthesis(int n) {
        vector<string> result;
        dfs(result, n, n, "");
        return result;
    }
};
