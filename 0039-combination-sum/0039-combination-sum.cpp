class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target, int i, vector<int>& path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (target < 0 || i == candidates.size()) return;
        
        // include candidates[i]
        path.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i, path);
        path.pop_back();
        
        // skip candidates[i]
        dfs(candidates, target, i+1, path);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(candidates, target, 0, path);
        return res;
    }
};
