class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp; 
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        int majority = nums.size() / 2;
        int highest = 0;
 


        for (const auto [key, freq] : mp)
            if (freq > majority) return key; 

    }
};