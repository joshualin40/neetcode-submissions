class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> map1;
        for (int i =0; i < s1.length(); i++)
        {
            map1[s1[i]]++;
        }
        int left = 0;
        int windowsize = s1.length(); 
        while (left + windowsize <= s2.length())
        {
            unordered_map<char, int> map2; 
            for (int i = left; i < left + windowsize; i++)
                map2[s2[i]]++;
            if (map1 == map2) return true;
            else left++;
        }
        return false;
    }
};
