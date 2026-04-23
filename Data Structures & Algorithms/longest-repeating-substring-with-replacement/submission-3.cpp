class Solution {
public:
    int characterReplacement(string s, int k) {
        // create hash table to keep track of char frequencies
        // add k to the highest frequency
        // that is initial window size. check this window size 
        // by seeing if the substring has k or fewer other elements
        // if this window size doesn't work go one lower until it works
        int left = 0;
        int windowsize = s.length();
        while (true)
        {
            unordered_map<char, int> map1; 
            for (int i = left; i < left + windowsize; i++)
            {
                map1[s[i]]++; 
            }
            int maxchar = 0;
            for (const auto& [key,value]: map1)
            {
                if (value > maxchar) maxchar = value; 
            }
            int nonmax = windowsize - maxchar; 
            if (nonmax <= k) return windowsize;
            else if (left + windowsize < s.length()) left++;
            else 
            {
                left = 0;
                windowsize--;
            }
        }
      

        //
    }
};
