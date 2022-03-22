#include <stack>
#include <string>
#include <vector>

using namespace std;

struct Node {
    bool isFile;
    int level;
    size_t length;
};

class Solution {
public:
    int LengthLongestPath(string input) {
        vector<Node> nodes = Split(input, '\n');
        stack<Node> stk;

        int longest = 0;
        int curt = 0;

        for (const auto& node : nodes) {
            while (!stk.empty() && stk.top().level >= node.level) {
                curt -= stk.top().length;
                stk.pop();
            }

            if (node.isFile) {
                curt += node.length;
                longest = max(longest, curt + node.level);
                curt -= node.length;
            } else {
                stk.push(node);
                curt += node.length;
            }
        }

        return longest;
    }
private:
    vector<Node> Split(const string& input, char delimiter) {
        vector<Node> result;
        string curt;

        for (const auto& c : input) {
            if (c != delimiter) {
                curt += c;
            } else if (!curt.empty()) {
                int level = CountLevel(curt);
                result.push_back({IsFile(curt), level, curt.length() - level});
                curt = "";
            }
        }

        if (!curt.empty()) {
            int level = CountLevel(curt);
            result.push_back({IsFile(curt), level, curt.length() - level});
        }

        return result;
    }

    int CountLevel(const string& input) {
        int level = 0;a
        
        for (const auto& c : input) {
            if (c == '\t') {
                ++level;
            }
        }

        return level;
    }

    bool IsFile(const string& input) {
        for (const auto& c : input) {
            if (c == '.') {
                return true;
            }
        }

        return false;
    }
};
