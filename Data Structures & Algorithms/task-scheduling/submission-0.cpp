class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int time = 0; 
    // when a task is performed. look at which element is most frequent afte

      // create a queue of pairs with its char and frequency 
        auto cmp = [](pair<char,int> a, pair<char,int> b) {
            return a.second > b.second; 
        }; 
        unordered_map<char, int> mp; 
        priority_queue<int> maxHeap; 
        for (int i = 0; i < tasks.size(); i++)
            mp[tasks[i]]++; 
        // now insert into a priority queue
        for (const auto [key, value]: mp)
            maxHeap.push({value});
        
        
        queue<pair<int, int>> q; // stores the remaning count of runing, next avaibl
        while (!q.empty() || !maxHeap.empty())
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
            if (!q.empty() && q.front().second == time)
            {
                maxHeap.push(q.front().first);
                q.pop(); 
            }
          
        }


        return time; 
    }
};
