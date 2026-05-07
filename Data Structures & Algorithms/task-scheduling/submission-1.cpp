class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int time = 0; 
        vector<int> counts(26, 0); 
        for (int i = 0; i < tasks.size(); i++) 
            counts[tasks[i] - 'A']++;

        priority_queue<int> maxHeap; 
        queue<pair<int, int>> q; // frequency, next available time
        for (int i = 0; i < counts.size(); i++)
            if (counts[i] > 0)
                maxHeap.push(counts[i]); 

        while (!maxHeap.empty() || !q.empty())
        {
            time++; 
            if (maxHeap.empty())
            {
                time = q.front().second;
            }
            else
            {
                int count = maxHeap.top() - 1;
                maxHeap.pop(); 
                if (count > 0)
                    q.push({count, time + n});
            }
            if (time == q.front().second && !q.empty())
            {
                maxHeap.push({q.front().first});
                q.pop(); 
            }
        }

        return time; 

    }
};
