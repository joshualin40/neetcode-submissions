class Solution {
public:
    int BinarySearch(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if (target > nums[mid]) left = mid + 1;
            else if (target < nums[mid]) right = mid - 1;
            else return mid; 
        }
        return -1; 
        // returns index of target
    }
    int search(vector<int>& nums, int target) {
        // we can go with the l, r, mid approach again
        // there are 4 cases
        // mid belongs to the left section and target is in between left and mid
        // mid belongs to the left section and target < left
        // mid belongs to the right section and target is in between mid and right
        // mid belongs to the right section and target > right
        int left = 0;
        int right = nums.size() - 1; 

        int cut = 0; // cut is the smallest element index
        if (nums[left] < nums[right]) cut = left; 
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) 
            {
                cut = mid + 1;
                break;
            }
            else if (nums[mid] > nums[left]) left = mid;
            else right = mid;
        }


        vector<int> leftvec(nums.begin(), nums.begin() + cut);
        vector<int> rightvec(nums.begin() + cut, nums.end());   
        if (BinarySearch(leftvec, target) != -1)
            return BinarySearch(leftvec,target);
        else if (BinarySearch(rightvec, target) != -1)
            return BinarySearch(rightvec, target) + cut;
        else return -1;
    }
};
