// bucket sort for n buckets (n is size of array), each bucket represents a specific frequency
// for example if the array was {1,1,1,1}, we would create an array of size 4 and 
// array[4] = 1; 
// first create a map, with key,value pairs of the number, and the frequency.
// then we can put all keys with value i into freq[i] for the whole map (freq is a vector of vector ints)




// afterwards, we start from the nth index of the array picking the top k numbers

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map; // key is the element, value is the frequency
        int size = nums.size(); 
        vector<vector<int>> freq(size + 1);
        vector<int> res;

        for (int i = 0; i < size; i++)
        {
            map[nums[i]]++; 
        }
        // now we have map filled. now, convert the map into a vector of size n
        for (const auto& [key, value] : map)
        {
            freq[value].push_back(key);
        }

        // now we want to pick the top K elements from freq
        // start at freq[size - 1]. if not empty then append element to the res vector and 
        // if empty then go to freq[size - 2]. 
        for (int i = freq.size() - 1; i > 0; i--)
        {
            for (int j = freq[i].size() - 1; j >=0; j--)
            { 
                res.push_back(freq[i][j]);
                if (res.size() == k) return res;
            }
        }

    }
};
