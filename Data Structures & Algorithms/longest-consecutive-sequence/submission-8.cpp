// A Hash Set is a form of Hash Table data structure 
// that usually holds a large number of elements.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // convert to hash set ->
        // iterate through the hash set
        // if the num - 1 doesnt exist, start the sequence there. 
        // if the sequence ends, break the inner loop and add the sequence length to a vector
        unordered_set<int> set(nums.begin(), nums.end());
        // unordered map of each key, and the longest seqeunce formed up to the key
        unordered_map<int, int> map; 
        
        sort(nums.begin(), nums.end());
        
        for (int i =0; i < nums.size(); i++) {
            if (set.contains(nums[i] - 1)) // it is possible that this element was not computed before 
                                        // we go, so we should iterate through the original vector
            {
                // if the previous element exists, add one to the previous length added to vector 
                // and append it to the vector
                int length = map[nums[i]-1] + 1;
                map[nums[i]] = length;
            }
            else
            {
                map[nums[i]] = 1;
                // add a 1 to the vector
            }
        }
        int max = 0; 
        for (const auto& [key, value]: map)
        {
            if (value > max) max = value;
        }
        return max; 

    }
};
