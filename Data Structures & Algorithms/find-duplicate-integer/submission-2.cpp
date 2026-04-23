class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // since all integers are between 1 and n 
        // we can use their values to be our new indices
        // (but you just subtract 1 from them since its 0-indexed)
        // go through the array, multiplying the corresponding index 
        // by negative one
        // if we encounter a negative then its a dup
        // eg if index 2 is negative, then the value at index 3 is a dup
        for (int i =0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] < 0) return abs(nums[i]);
            else (nums[abs(nums[i]) - 1] *= -1);
        }
    }
};
