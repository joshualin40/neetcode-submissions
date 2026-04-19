class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // rearrange the equation into nums[i] + nums[j] = -nums[k]

        vector<vector<int>> res; 
        sort(nums.begin(), nums.end());
        for (int k =0; k < nums.size(); k++)
        {
            int target = nums[k] * -1; 
            int left = k+1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (k == left) left++; 
                if (k == right) right--;
        
                if (nums[left] + nums[right] < target) left++;
                else if (nums[left] + nums[right] > target) right--;
                else if (nums[left] + nums[right] == target) 
                {
                    vector<int> v = {nums[left], nums[right], nums[k]};
                    sort(v.begin(), v.end());
                    res.push_back(v);
                    left++;
                    right--;
                }
            }
        }

        // now remove all dups from 
        sort(res.begin(), res.end());
        auto last = unique(res.begin(), res.end());
        res.erase(last, res.end());

        return res;
    }
};
