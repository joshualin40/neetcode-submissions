class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int time = 0; 
        for (int i = 0; i < 1000; i++)
        {
            int passengers = 0;
            for (int j = 0; j < trips.size(); j++)
            {
                if (time >= trips[j][1] && time < trips[j][2])
                    passengers += trips[j][0];
            }
            if (passengers > capacity) return false;
            time++; 
        }

        return true; 
    }
};