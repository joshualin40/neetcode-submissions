class Solution {
public: 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count frequency of each number, store it in a hash map.
        // then sort original array based on the hash map
        unordered_map<int, int> map;
        for (int i =0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        // now we have a map with key, value pairs of each num in the original vector
        // dump the map into vector of int int vectors
        vector<vector<int>> v;
        for (const auto& [key, value] : map)
        {
            v.push_back({key,value});
        }
        // now we have the sort based on the second int
        sort(v.begin(), v.end(), [](const auto& a, const auto&b) 
        {return a[1] > b[1];});

        vector<int> result;

        for (int i =0; i < k; i++)
        {
            result.push_back(v[i][0]);
        }

        return result;
    }
};
