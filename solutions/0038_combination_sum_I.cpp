#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) {
            return {};
        }
        
        vector<vector<int>> result;
        vector<int> tmp;
        dfs(result, tmp, candidates, target, 0);

        return result;
    }

private:
    void dfs(vector<vector<int>>& result, vector<int>& tmp, 
             const vector<int>& candidates, int target, int index)
    {
        if (target == 0) {
            result.push_back(tmp);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (target >= candidates[i]) {
                tmp.push_back(candidates[i]);
                dfs(result, tmp, candidates, target - candidates[i], i);
                tmp.pop_back();
            }   
        }
    }
};
