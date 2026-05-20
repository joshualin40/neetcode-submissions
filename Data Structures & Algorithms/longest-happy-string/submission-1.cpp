class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
    // again we need to choose the most frequent string
    // after 2     
    priority_queue<pair<int, char>> pq; 
    string res; 
    
    if (a != 0)
        pq.push({a, 'a'}); 
    if (b != 0) 
        pq.push({b, 'b'}); 
    if (c != 0) 
        pq.push({c, 'c'}); 
    bool repeated = false; 
    char lastchar; 
    while (!pq.empty())
    {
        auto top = pq.top(); 
        if (repeated == true && top.second == lastchar)
        {
            pq.pop(); 
            lastchar = top.second; 
            auto top2 = pq.top(); 
            if (top2.second == lastchar) break;
            else
            {
                res += top2.second;
                lastchar = top2.second; 
                pq.pop(); 
                if (top2.first > 1)
                    pq.push({top2.first - 1, top2.second});
                if (top.first > 1)
                    pq.push({top.first, top.second});
            }
        }
        else
        {
            if (lastchar == top.second)
                repeated = true; 
            else repeated = false;   
            res += top.second; 
            lastchar = top.second; 
            pq.pop(); 
            if (top.first > 1)
                pq.push({top.first - 1, top.second});
        }
    }
        return res; 
    }
};