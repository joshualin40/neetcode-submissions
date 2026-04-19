// first try with O(n3) time
// there shouldn't be any duplicate trips

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i =0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                for (int k = j+1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0) 
                    {
                        vector<int> v = {nums[i],nums[j],nums[k]};
                        sort(v.begin(), v.end());
                        bool exists = false;
                        for (int n=0; n < res.size(); n++)
                        {
                            if (v == res[n]) exists = true;
                        }
                        if (!exists)
                            res.push_back(v);
                    }
                }
            }
        }

        // remove dups from res


        return res;
    }
};
