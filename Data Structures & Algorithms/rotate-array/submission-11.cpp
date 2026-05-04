// implement helper reverse function
// reverse entire array, then reverse first K elements of array/
// then reverse rest of array

class Solution {
    void reverse(vector<int>& nums, int l, int r) // l and r are the index
    // that bound the reversal
    {
        while (l <= r)
            swap(nums[l++], nums[r--]);
    }
public:
    void rotate(vector<int>& nums, int k) {
        k%= nums.size();

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k-1);
        reverse(nums,k,nums.size() - 1);
        
    }
};