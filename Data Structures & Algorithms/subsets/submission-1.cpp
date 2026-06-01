class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset; 
        dfs(0,subset, nums, res);
        return res; 
    }

    void dfs(int i, vector<int>& subset, vector<int> &nums, vector<vector<int>>& res) // i = index of the value we are making the decision on 
    {
        if (i == nums.size())
        {
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[i]);
        dfs(i+1, subset, nums, res); 

        subset.pop_back(); 
        dfs(i+1, subset, nums, res);
    }
};
