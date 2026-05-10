class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] <= nums[r]) return nums[l];

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid + 1] < nums[mid]) return nums[mid + 1];
            else if (nums[mid] > nums[l]) l = mid; 
            else r = mid;
        }

        return r;
    }
};
