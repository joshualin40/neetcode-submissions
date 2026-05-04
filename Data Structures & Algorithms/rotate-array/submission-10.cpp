// slice and concatenate

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // take last K elements of array and put them at the front
        std::rotate(nums.begin(), nums.end() - (k % nums.size()), nums.end());
    }
};