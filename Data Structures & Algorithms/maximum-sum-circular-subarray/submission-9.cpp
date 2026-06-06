class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum = 0; 
        // regular kadanes
        int currsum = nums[0];
        int regular = currsum; 

        for (int i = 1; i < nums.size(); i++)
        {
            currsum = max(nums[i], nums[i] + currsum);
            regular = max(regular, currsum);
        }

        // kadane to find min subarray
        for (int i = 0; i < nums.size(); i++)
            totalsum += nums[i];
        int currmin = nums[0];
        int minsubarray = currmin; 
        for (int i = 1; i < nums.size(); i++)
        {
            currmin = min(nums[i], nums[i] + currmin);
            minsubarray = min(minsubarray, currmin);
        }
        if (totalsum == minsubarray) return regular;


        return max(totalsum - minsubarray, regular); 
    }
};