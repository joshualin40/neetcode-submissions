/* 
Sort tasks by enqueue time (keeping track of original index)
Use a pointer to track which tasks have been added to the heap
Each iteration: push all newly available tasks into the heap, then process the top
If the heap is empty, jump time forward to the next task's enqueue time */ 

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // make two min-heaps. one for the available tasks 
        // one for pending tasks  
        vector<int> res;
        int time = 1; 
        // the minheap of pairs has the processingtime, then index as the enqueue time is 
        // irrelevant if its availbkae
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> available;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pending;
        // array -> enqueuetime, processingtime, index
        // first put all tasks in pending
        // then, when after each task processes, remove tasks from pending until the 
        // enqueue of the front of pending is greater than current time
        // then process the top of available
        // do this until the pending array is empty 
        for (int i = 0; i < tasks.size(); i++)
        {
            pending.push({tasks[i][0], tasks[i][1], i});
        }
        while (!pending.empty() || !available.empty())
        {
            while (pending.top()[0] < time && !pending.empty())
            {
                auto temp = pending.top();
                available.push({temp[1], temp[2]});
                pending.pop(); 
            }
            if (!available.empty())
            {
                auto temp = available.top(); 
                time+= temp.first;
                res.push_back(temp.second); 
                available.pop(); 
            }
            else
                time++; 
        }

        return res; 
    }
};