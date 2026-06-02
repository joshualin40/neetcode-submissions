class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int l = 0; int r = matrix.size() - 1;
        int row = 0; 
        bool rowfound = false; 
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (matrix[mid][0] <= target && matrix[mid][matrix[mid].size() - 1] >= target)
            {
                rowfound = true; 
                row = mid; break;
            } 
            else if (matrix[mid][0] > target)
                r = mid - 1; 
            else if (matrix[mid][matrix[mid].size() - 1] < target)
                l = mid + 1;
        }
        if (!rowfound)
            return false;

        int left = 0; int right = matrix[row].size() - 1;
        while (left <= right)
        {
            int newmid = left + (right - left) / 2;

            if (matrix[row][newmid] == target)
                return true; 
            else if (matrix[row][newmid] > target)
                right = newmid - 1;
            else 
                left = newmid + 1;
        }
        return false; 
    }
};
