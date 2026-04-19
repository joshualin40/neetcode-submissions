class Solution {
public:
    int maxArea(vector<int>& heights) {
        // if the answer is i, j, the maxArea is (i-j) * max(heights[i], heights[j])
        // brute force first: 
        vector<int> areas;
        for (int i =0; i < heights.size(); i++)
        {
            for (int j = i + 1; j < heights.size(); j++)
            {
                areas.push_back((j-i) * min(heights[i], heights[j]));
            }
        }

        sort(areas.begin(), areas.end());
        return areas.back();
    }
};
