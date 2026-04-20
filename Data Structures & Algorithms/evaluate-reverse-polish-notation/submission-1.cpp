class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     // when you see an operator,perform the operation on the two ints on the 
     // stack and push the result on the stack    
     stack<string> s; 
     for (int i =0; i < tokens.size(); i++)
     {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int a = stoi(s.top()); s.pop(); 
            int b = stoi(s.top()); s.pop(); 
            if (tokens[i] == "+") s.push(to_string(a+b));
            else if (tokens[i] == "-") s.push(to_string(b-a));
            else if (tokens[i] == "*") s.push(to_string(a*b));
            else if (tokens[i] == "/") s.push(to_string(b/a));
        }
        else s.push(tokens[i]);
     }
     return stoi(s.top());
    }
};
