class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 0; 
        int currsum = 1; 

        int prev = -1; // if 0, then the last pair was ascnending
        // 1 the last pair was descending
        // if -1, no value yet


        for (int i = 0; i < arr.size() - 1; i++)
        {
            int curr; 
            if (arr[i] < arr[i + 1])
                curr = 0; 
            else if (arr[i] > arr[i + 1])
                curr = 1;
            else {
                res = max(currsum, res);
                currsum = 1;
                prev = -1;
                continue;
            }

            if (curr == prev)
            {
                res = max(currsum, res);
                currsum = 2;
            }
            else currsum++; 

            prev = curr; 
        }
        res = max(currsum, res);
        return res; 
    }
};