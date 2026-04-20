class Solution {
public:
    bool isValid(string s) {
        // iterate through string. when you see a left bracket push it onto a stack
        // when you see the right bracket, visit top of stack and pop it
        // if the top isn't the corresponding left bracket return false
        // return false if you try to pop an empty stack

        stack<char> charstack;
        for (int i =0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                charstack.push(s[i]);
            else if (charstack.size() == 0) return false;
            else
            {
                if (s[i] == ')')
                    {
                        if (charstack.top() != '(') return false;
                        else charstack.pop(); 
                    }
                if (s[i] == ']')
                    {
                        if (charstack.top() != '[') return false;
                        else charstack.pop(); 
                    }
                if (s[i] == '}')
                    {
                        if (charstack.top() != '{') return false;
                        else charstack.pop(); 
                    }
            }
            
        }

        if (charstack.size() != 0) return false;

        return true;
    }
};
