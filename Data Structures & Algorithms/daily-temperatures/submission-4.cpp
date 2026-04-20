// brute force O(n^2)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // how many days away is a higher temp from temperatures[i]? 
        // put that number into results[i]. if no higher temps after set 0
        
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size() - 1; i++)
        {
            bool hasfuture = false;
            for (int j = i+1; j < temperatures.size(); j++)
            {
                if (temperatures[j] <= temperatures[i]) result[i]++;
                else 
                {
                    result[i]++; 
                    hasfuture = true;
                    break;
                }
            }
            if (!hasfuture) result[i] = 0;
      
        }
        result[temperatures.size()-1] = 0;

        return result;
    }
};
