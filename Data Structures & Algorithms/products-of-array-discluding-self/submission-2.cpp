// O(n) time using prefix 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size= nums.size();
        vector<int> suffix(size);
        vector<int> prefix(size);
        vector<int> res(size);

        suffix[0] = 1;
        prefix[size - 1] = 1;
        for (int i = 1; i < size; i++)
        {
            suffix[i] = suffix[i-1] * nums[i-1];
        }
        for (int i = size - 2; i >= 0; i--)
        {
            prefix[i] = prefix[i+1] * nums[i+1];
        }
        for (int i = 0; i < size; i++)
        {
            res[i] = suffix[i] * prefix[i];
        }

        return res;
    }
};
