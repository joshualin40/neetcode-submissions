class Solution {
   vector<vector<int>> res; 
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset; 
        sort(nums.begin(), nums.end());
        backtrack(0, subset, nums);
        return res;
    }

    void backtrack(int i, vector<int>& subset, vector<int>& nums)
    {
        if (i == nums.size())
        {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(i + 1, subset, nums);
        subset.pop_back(); 
        while (i < nums.size() - 1 && nums[i] == nums[i+1])
            i++; 
        backtrack(i + 1, subset, nums);
    }
};
