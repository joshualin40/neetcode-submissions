class Solution {
public:
    int maxArea(vector<int>& heights) {
        // formula is abs((i-j) * min(heights[i], heights[j]))
        int size = heights.size();

        // start with two pointers at each end. 
        // decrease the right pointer if the next one is greater than the min of the current heights
        // same with the left
        // you should only change the lower one, as the area can only get bigger if the height increases
        int left = 0; 
        int right = size -1;
        // get the larger one from changing left or changing
        int max = 0;
        while (left < right)
        {
            if ((right-left) * min(heights[left], heights[right]) > max) 
                max = (right-left) * min(heights[left], heights[right]);
            
            if (heights[left] <= heights[right]) left++;
            else if (heights[left] > heights[right]) right--;
            
        }
        return max;

    }
};
