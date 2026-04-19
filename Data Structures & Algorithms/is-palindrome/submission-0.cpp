class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = ""; 
        for (int i =0; i < s.length(); i++)
        {
            if (isalpha(s[i]) || isdigit(s[i]))
            {
                s[i] = tolower(s[i]);
                cleaned += s[i];
            }
        }
        for (int i = 0; i < cleaned.length()/2; i++)
        {
            if (cleaned[i] != cleaned[cleaned.length() - 1 - i]) return false;
        }
        return true;
    }
};
