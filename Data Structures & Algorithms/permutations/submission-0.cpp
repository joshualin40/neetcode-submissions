class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms = {{}};
        for (int i = 0; i < nums.size(); i++)
        {
            vector<vector<int>> new_perms; 
            for (int j = 0; j < perms.size(); j++)
            {
                for (int k = 0; k <= perms[j].size(); k++)
                {
                    vector<int> copy = perms[j];
                    copy.insert(copy.begin() + k, nums[i]);
                    new_perms.push_back(copy);
                }
            }
            perms = new_perms; 
        }
        return perms;
    }
};
