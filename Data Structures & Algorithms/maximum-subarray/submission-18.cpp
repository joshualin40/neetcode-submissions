class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = nums[0];
        int res = currsum;

        for (int i = 1; i < nums.size(); i++)
        {
           currsum = max(nums[i], currsum + nums[i]);

           res = max(res, currsum);
        }

        return res; 
    }
};
