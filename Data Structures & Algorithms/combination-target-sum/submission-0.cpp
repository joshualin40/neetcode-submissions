class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res; 
        vector<int> comb;
        backtrack(0, target, 0, nums, comb, res);

        return res;

    }

    void backtrack(int i, int target, int cur, vector<int>& nums, vector<int> &comb, vector<vector<int>> &res)
    {
        if (cur == target) // base case reached
        {
            res.push_back(comb); 
            return; 
        }
        while (i < nums.size())
        {
            if (cur + nums[i] <= target)
            {
                comb.push_back(nums[i]);
                backtrack(i, target, cur + nums[i], nums, comb, res);

                comb.pop_back();
            }
            i++;
        }
    }
};
