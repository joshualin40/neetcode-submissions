class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int left = 0;
        int right = 1;
        while (right < s.length())
        {
            bool hasdup = false;
            string substring = s.substr(left,right-left+1);
            unordered_map<char, int> set1; 
            for (int i = 0; i < substring.length(); i++)
                set1[substring[i]]++; 
            for (const auto& [key,value] : set1)
            {
                if (value > 1) hasdup = true;
            }
            if (hasdup) 
            {
                left++;
                right++;
            }
            else
            {
                right++;
            }
        }
        return right - left;
    }
};
