class Solution {
public:
// combination of K numbers from [1,n]

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res; 
        vector<int> comb; 
        backtrack(n, 1, k, comb, res);
        return res; 
    }

    void backtrack(int n, int i, int k, vector<int>& comb, vector<vector<int>>& res)
    {
        if (i > n)
        {
            if (comb.size() == k)
                res.push_back(comb);
            return;
        }
        
        comb.push_back(i);
        backtrack(n, i + 1, k, comb, res);
        comb.pop_back(); 
        backtrack(n, i+1, k, comb, res);
    }
};