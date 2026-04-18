class Solution {
public:
    void swap(char& a, char& b)
    {
        char temp = a;
        a = b;
        b = temp;
    }

    void SelectionSort(string& str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            int min = i; 
            for (int j = i + 1; j < str.size(); j++)
            {
                if (str[j] < str[min]) min = j;
            }
            swap(str[min], str[i]);
        }
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort each string and group them with hash map
        // key, value -> sorted string, vector of strings that match
        
        
        vector<string> sortedstrings;
        // iterate through the vector of strings, sorting them and putting them into sortedstrings
        for (int i = 0; i < strs.size(); i++)
        {
            string copy = strs[i];
            SelectionSort(copy);
            sortedstrings.push_back(copy);
        }

        // now sortedstrings is filled with sorted strings
        unordered_map<string, vector<string>> map; 
        for (int i = 0; i < sortedstrings.size(); i++)
        {
            map[sortedstrings[i]].push_back(strs[i]);
        }

        // now turn the map into a vector of string vectors
        vector<vector<string>> returnvector;
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            returnvector.push_back(it->second);
        }

        return returnvector;
    }
};
