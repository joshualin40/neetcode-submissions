class Solution {
public:
    int majorityElement(vector<int>& nums) {
        while (true)
        {
            int n = rand() % (nums.size());
            int count = 0;
            for (int i = 0; i < nums.size(); i++)
                if (nums[i] == nums[n]) count++;
            
            if (count > nums.size() / 2) return nums[n];
        }
    }
};