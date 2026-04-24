class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search twice
        int left = 0; 
        int right = matrix.size() - 1;
        int row = 0; 
        bool rowfound = false;
        while (left <= right)
        {
            int mid = left + (right - left) / 2; 

            if (target > matrix[mid][matrix[mid].size() - 1])
                left = mid + 1;
            else if (target < matrix[mid][0]) right = mid - 1;
            else 
            {
                row = mid; 
                rowfound = true;
            }
        }
        if (!rowfound) return false;


        int newleft = 0; 
        int newright = matrix[row].size() - 1;

        while (newleft <= newright)
        {
            int newmid = newleft + (newright - newleft) / 2; 

            if (target > matrix[row][newmid])
                newleft = newmid + 1;
            else if (target < matrix[row][newmid])
                newright = newmid - 1;
            else return true;
        }

        return false;
    }
};
