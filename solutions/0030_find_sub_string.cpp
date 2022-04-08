#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        if (words.empty()) {
            return {};
        }

        int n = s.size();
        unordered_map<string, int> cnt;

        for (const auto& word : words) {
            ++cnt[word];
        }
        
        int wLen = words[0].size();
        int wCnt = words.size();
        int len = wLen * wCnt;

        vector<int> result;
        for (int i = 0; i < n - len + 1; ++i) {
            string str = s.substr(i, len);
            unordered_map<string, int> subCnt;

            for (int j = 0; j < str.size(); j += wLen) {
                string w = str.substr(j, wLen);
                ++subCnt[w];
            }

            if (match(subCnt, cnt)) {
                result.push_back(i);
            }

        }

        return result;
    }
private:
    bool match(unordered_map<string, int>& cnt1, unordered_map<string, int>& cnt2)
    {
        bool match = true;
        for (const auto& [w, c] : cnt1) {
            if (cnt2.find(w) == cnt2.end() || cnt1[w] != cnt2[w]) {
                match = false;
                break;
            }
        }

        return match;
    }
};