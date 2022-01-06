#include <string>

using namespace std;

class Solution {
private:
    const string kstr[8] = {
        "abc", "def", "ghi", "jkl", 
        "mno", "pqrs", "tuv", "wxyz"
    };

    void dfs(vector<string>& result, const string& digits, int index, string& path) {
        if (index == digits.length()) {
            result.push_back(path);
            return;
        }

        string letters = kstr[digits[index] - '2'];

        for (const auto& letter : letters) {
            path.push_back(letter);
            dfs(result, digits, index + 1, path);
            path.pop_back();
        }
    }
public:
    vector<string> letter_combinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> result;
        string path;
        dfs(result, digits, 0, path);
        return result;
    }
};
