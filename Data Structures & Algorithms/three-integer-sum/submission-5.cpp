class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // do the two pointer method but treating the target as the negative of the third
        // element
        int size = nums.size(); 
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        for (int i =0; i < size; i++)
        {
            int target = nums[i] * -1;
            int left = i+1;
            int right = size-1;
            while (left < right)
            {
                if (nums[left] + nums[right] > target) right--;
                else if (nums[left] + nums[right] < target) left++;
                else if (nums[left] + nums[right] == target)
                {
                    res.insert({nums[left], nums[right], nums[i]});
                    left++;
                    right--;
                }
            }
        }
        vector<vector<int>> result;
        for (const auto& elem : res)
        {
            result.push_back(elem);
        }
        return result;

    }
};
