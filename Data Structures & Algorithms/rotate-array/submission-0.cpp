// easy solution: create a rotate function and call it K times

class Solution {
public:
    void rotate(vector<int>& nums)
    {   
        vector<int> reference = nums; 
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = reference[(i + nums.size() - 1) % nums.size()]; 
        }
    }
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)
            rotate(nums);
    }
};