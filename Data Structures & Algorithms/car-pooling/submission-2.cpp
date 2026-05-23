class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int> &a, const vector<int> & 
        b) {return a[1] < b[1];}); //sorted by pickup time

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap; 
        // dropoff timme, passengers

        int currpass = 0;
        for (int i = 0; i < trips.size(); i++)
        {
            currpass += trips[i][0];

            // if the pickup time is greater than the dropoff time in the minheap
            // pop and subtract 
            while (!minHeap.empty()) 
            {
                if (minHeap.top().first > trips[i][1]) break;
                currpass -= minHeap.top().second; 
                minHeap.pop();
            }
            if (currpass > capacity) return false;
            minHeap.push({trips[i][2], trips[i][0]});
            
        }

        return true;
    }
};