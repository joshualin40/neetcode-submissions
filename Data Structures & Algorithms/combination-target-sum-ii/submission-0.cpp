class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> comb; 
        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, target, candidates, comb, res);
        return res; 
    }

    void backtrack(int i, int cur, int target, vector<int>& candidates, vector<int>& comb, vector<vector<int>>& res)
    {
        if (cur == target)
        {
            res.push_back(comb);
            return;
        }
        if (i == candidates.size() || cur > target) return; 

        comb.push_back(candidates[i]);
        backtrack(i + 1, cur + candidates[i], target, candidates, comb, res);
        comb.pop_back(); // first recursive call

        while (i + 1 < candidates.size() && candidates[i] == candidates[i+1])
            i++; 
        
        backtrack(i + 1, cur, target, candidates, comb, res); 
    }
};
