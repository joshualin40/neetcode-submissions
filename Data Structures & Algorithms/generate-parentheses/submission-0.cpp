class Solution {
    vector<string> res; 
public:
    void dfs(int front, int back, int index, int n, string subset)
    {
        if (back > front || front > n) return;
        if (index == 2 * n - 1) 
        {
            res.push_back(subset);
            return; 
        }

        // first case, if back is equal to front append to res
        

        dfs(front + 1, back, index + 1, n, subset + "(");
        // second case, add (
        
        dfs(front, back + 1, index + 1, n, subset + ")");
        // third case, add )

    }
    vector<string> generateParenthesis(int n) {
        // condition for invalid string: number of back parentheses is greater then 
        // the amount of forward parentheses 
        // or number of front parentheses is greater than n
        // ())( invalid, but we would never get to that stage because after ()) 
        // the backtracking function would return it  
        dfs(0,0,-1,n,"");

        return res; 

    }
};
