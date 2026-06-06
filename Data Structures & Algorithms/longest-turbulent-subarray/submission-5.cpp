class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() < 2) return arr.size(); 
        int res = 0; 
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int currlength = 2; 
            if (arr[i + 1] > arr[i])
            {
                for (int k = i + 1; k < arr.size() -1; k++)
                {
                    if ((k - i) % 2 == 0)
                    {
                        if (arr[k+1] > arr[k])
                            currlength++;
                        else break;
                    }
                    else 
                    {
                        if (arr[k+1] < arr[k])
                            currlength++;
                        else break;
                    }
                }
                res = max(res, currlength);
            }
            else if (arr[i + 1] < arr[i])
            {
                for (int k = i + 1; k < arr.size() - 1; k++)
                {
                    if ((k - i) % 2 == 1)
                    {
                        if (arr[k+1] > arr[k])
                            currlength++;
                        else break;
                    }
                    else 
                    {
                        if (arr[k+1] < arr[k])
                            currlength++;
                        else break;
                    }
                }
                res = max(res, currlength);
            }
            else {
                res = max(1, res); 
            };
        }

        return res;
    }
};