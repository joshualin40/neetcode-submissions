class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // iterate through array putting them on a stack
        // if it has negative and smaller than top, dont push 
        // if it has negative and same as top. pop top
        // if it has negative and larger than top
            // pop all asteroids on stack smaller than it
        
        // afterwards put the stack in a vector
        stack<int> s; 
        vector<int> v; 
        for (int i =0; i < asteroids.size(); i++)
        {
            if (asteroids[i] > 0) s.push(asteroids[i]);
            if (asteroids[i] < 0 && !s.empty()) // after each push
            // a positive number will be left on top of the stack so we can assume
            // there is a positive number on top of the stack
            {
                if (s.top() > 0)
                {
                    if (abs(asteroids[i]) > s.top())
                        {
                            while (!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i]))
                                s.pop();
                            
                            if (!s.empty() && s.top() < 0)
                                s.push(asteroids[i]);
                            else if (s.empty()) s.push(asteroids[i]);
                            else if (s.top() == abs(asteroids[i])) s.pop(); 
                        }
                    else if (abs(asteroids[i]) == s.top()) s.pop();
                    else if (abs(asteroids[i]) < s.top())
                    {} // do nothing
                }
                else
                {
                    s.push(asteroids[i]);
                }
            }
            else if (asteroids[i] < 0 && s.empty())
            {
                s.push(asteroids[i]);
            }
        }
        while (!s.empty())
        {  
            int temp = s.top(); 
            v.insert(v.begin(), temp);
            s.pop();
        }

        return v; 
    }
};