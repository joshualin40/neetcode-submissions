class Solution {
public:
    int findMin(vector<int> &nums) {
        // rotating the array puts the end of the array ot the beginning and shifts
        // everything else up one 
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] <= nums[r]) return nums[l]; // already sorted 
        while (l < r)
        {
            int mid = l + (r-l) / 2;

            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            else if (nums[mid] > nums[l]) l = mid;
            else r = mid;
        }   

        return nums[r];

    }
};
