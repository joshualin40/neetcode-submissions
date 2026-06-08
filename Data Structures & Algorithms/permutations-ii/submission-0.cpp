class Solution {
    vector<vector<int>> res;
    unordered_map<int, int> count; 
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            count[nums[i]]++; 
        vector<int> perm; 
        backtrack(nums, perm);
        return res; 
    }

    void backtrack(vector<int> nums, vector<int> &perm)
    {
        if (perm.size() == nums.size())
        {
            res.push_back(perm);
            return;
        }
        for (auto& [num, cnt] : count) {
            if (cnt > 0) {
                perm.push_back(num);
                cnt--;
                backtrack(nums, perm);
                cnt++;
                perm.pop_back();
            }
        }
    }
};