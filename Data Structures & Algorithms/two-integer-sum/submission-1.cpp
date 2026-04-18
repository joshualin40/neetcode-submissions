class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // iterate through the vector storing the index, value in a hash map
        // if the difference exists in the hash map, return current index and the index
        // of the difference

        // the map is index, value
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            // store the index and value in the map
            int difference = target - nums[i];
            // search if any of the VALUES in the hash map are equal to difference
            // if so, return the index of the difference and current index
            if (map.count(difference)) return {map[difference], i};

            map[nums[i]] = i; // 
        }    
        return {0,0};

        // map is full of nums[i], i pairs
        // iterate through the vector letting temporary int difference be the 
        // differnce between the target value and value at current index
        // if difference is in the map, return the a vector
        // with the value at difference (ie. the index
        // where the vector is equal to difference) and curretn index 
        }
};
