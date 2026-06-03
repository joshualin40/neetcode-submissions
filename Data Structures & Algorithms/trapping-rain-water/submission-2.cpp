class Solution {
public:
    int trap(vector<int>& height) {
        // water cant be trapped at the ends
        // the amount of water at index i is determined its value, and 
        // the smaller of the height of the left and right
        int res = 0; 
        for (int i = 0; i < height.size(); i++)
        {
            int right = height[i];
            int left = height[i];
            for (int j = i; j < height.size(); j++)
                right = max(right, height[j]);
            
            for (int k = i; k >= 0; k--)
                left = max(left, height[k]);

            if (right > height[i] 
                && left > height[i])
                res += min(right, left) - height[i];
    
        }
        return res; 
    }
};
