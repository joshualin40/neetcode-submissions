class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // for each string in the vector it has an array of size 26
        // array is the key in a map
        // if the array matches 
        unordered_map<string, vector<string>> map;
        for (int i =0; i < strs.size(); i++)
        {
            int array[26] = {0}; 
            for (int j =0; j < strs[i].size(); j++)
            {
                array[strs[i][j] - 'a']++;
            }
            // we must first convert the array into a string
            // make sure there are commas between counts, as if there are over 9
            // counts of a char things will get messy
            string key = "";
            for (int k = 0; k < 26; k++)
            {
                key += to_string(array[k]);
                key += " ";
            }
            map[key].push_back(strs[i]);
        }

         vector<vector<string>> returnvector;
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            returnvector.push_back(it->second);
        }

        return returnvector;
        
    }
};
