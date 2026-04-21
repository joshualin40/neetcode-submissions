class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        

        string res = "";
        for (int i = 0; i < strs[0].size(); i++)
        {
            char current = strs[0][i];
            bool included = true;
            for (int j =1; j < strs.size(); j++)
            {
                if (strs[j][i] != current) 
                {
                    included = false; 
                    return res;
                }
            }
            if (included) res += current;
        }

        return res;

        
    }
};