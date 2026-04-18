class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    
    vector<int> output;
        for (int i = 0; i < nums.size(); i++)
        {
            int product = 1; 
            for (int j = 0; j < nums.size() - 1; j++)
            {
                product *= nums[(i + 1+ j) % nums.size()];
            }
            output.push_back(product); 
        }
        return output;
    }
};
