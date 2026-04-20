class Solution {
public:
    int maxArea(vector<int>& heights) {
    // two pointers method but 
    // area is right - left x min(height[right], height[left])
    // you should only move the lower height as if you move the higher height you will not get 
    // a larger area
    int left = 0;
    int right = heights.size() - 1;
    int max = 0;
    while (left < right)
    {   
        int current = (right - left) * min(heights[right], heights[left]); 
        if (current > max) max = current;

        if (heights[left] >= heights[right]) right--;
        if (heights[left] < heights[right]) left++;
    }
        return max;
    }
};
