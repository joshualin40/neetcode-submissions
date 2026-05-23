class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset; 
        dfs(nums, 0, subset, res);
        return res;
    }

    void dfs(const vector<int>& nums, int n, vector<int>& subset, vector<vector<int>>& res)
    {
        if (n >= nums.size()) // out of bounds which means 
        {
            res.push_back(subset);
            return;
        }
        // include
        subset.push_back(nums[n]);
        dfs(nums, n + 1, subset, res);

        subset.pop_back();
        dfs(nums, n + 1, subset, res);
    }
};
