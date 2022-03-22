#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string SimplifyPath(string path) {
        vector<string> names = Split(path, '/');
        stack<string> stk;

        for (const auto& name : names) {
            if (name == ".") {
                continue;
            }

            if (name != "..") {
                stk.push(name);
            } else if (!stk.empty()) {
                stk.pop();
            }
        }

        if (stk.empty()) {
            return "/";
        }

        string result;

        while (!stk.empty()) {
            result = "/" + stk.top() + result;
            stk.pop();
        }

        return result;
    }
private:
    vector<string> Split(const string& path, char delimiter) {
        vector<string> result;
        string curt;

        for (const auto& c : path) {
            if (c != delimiter) {
                curt += c;
            } else if (!curt.empty()) {
                result.emplace_back(curt);
                curt = "";
            }
        }

        if (!curt.empty()) {
            result.emplace_back(curt);
        }        
        
        return result;
    }
};
