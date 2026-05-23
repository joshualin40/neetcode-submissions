class Solution {
    void backtrack(int i, vector<int>& nums, vector<int>& subset, int& res)
    {
        int xorr = 0;
        for (int k = 0; k < subset.size(); k++)
            xorr ^= subset[k]; 
        res += xorr; // adds the bitwise XOR of all elements in current subset

        // here is the backtracking...
        for (int j = i; j < nums.size(); j++)
        {
            subset.push_back(nums[j]); // add the current element back into subset
            backtrack(j + 1, nums, subset, res); // recursively call the backtrack function for the 
            // j + 1th subset
            subset.pop_back(); // remove the end of the subset
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0; 
        vector<int> subset;
        backtrack(0, nums, subset, res);
        return res; 
    }
};