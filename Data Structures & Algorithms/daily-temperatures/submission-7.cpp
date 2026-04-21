class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s; // store index, value
        vector<int> result(temperatures.size());
        for (int i =0; i < temperatures.size(); i++)
        {
            if (s.empty() || temperatures[i] < s.top().second) s.push({i,temperatures[i]});
            else
            {
                int tempindex = i;
                int tempvalue = temperatures[i];
                while (!s.empty() && s.top().second < tempvalue)
                {
                    int index = s.top().first; 
                    result[index] = tempindex - index;
                    s.pop();
                }
                s.push({tempindex, tempvalue});
            }
        }

        return result;
    }
};
